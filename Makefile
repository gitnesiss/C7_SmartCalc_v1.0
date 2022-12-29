CC      =gcc
CFLAGS  =-Werror -Wextra -Wall -std=c11
OS_NAME =$(shell uname)
BRANCH_INFO       =--rc lcov_branch_coverage=1
REMOVE_DIRECTIVES =clean_mode=1
SRC_DIR           =SCalc
BUILD_DIR         =build
TEST_DIR          =tests
TEMP_DIR          =tests/temp
REPORT_DIR_GCOV   =tests/report_gcov
REPORT_DIR_LCOV   =tests/report_lcov
	
#------------------ V Распознование системы и выбора флагов V -----------------



ifeq ($(OS_NAME), Linux)
	OPEN        =xdg-open
	TEST_FLAGS  =--coverage $(shell pkg-config --libs check)
	LEAK_CHECK  =valgrind --trace-children=yes --track-fds=yes \
	--track-origins=yes --leak-check=full --show-leak-kinds=all \
	--log-file="report.txt" ./$(TEST_DIR)/tests.out
	CFLAGS_LIBS =-lm -lsubunit -lpthread -lrt
else
	OPEN        =open -a "Google Chrome"
	TEST_FLAGS  =--coverage -lm -lcheck
	LEAK_CHECK  =CK_FORK=no leaks --atExit -- ./$(TEST_DIR)/tests.out
	CFLAGS_LIBS =-lm -L /usr/local/lib #-lcheck
endif

#------------------ ^ Распознование системы и выбора флагов ^ -----------------

all: install dist

install: dvi
	qmake CONFIG+=release -o $(BUILD_DIR)/Makefile SCalc/scalc.pro
	-cd $(BUILD_DIR); make
	-cd $(BUILD_DIR); make clean
	-rm -rf $(BUILD_DIR)/Makefile
	-rm -rf $(BUILD_DIR)/.qmake.stash
	-rm -rf $(BUILD_DIR)/qmake_qmake_qm_files.qrc
	-rm -rf $(BUILD_DIR)/.qm

start:
	open $(BUILD_DIR)/scalc.app

uninstall: clean

#------------------------ V Создание архивного файла V ------------------------

dist:
	mkdir -p $(BUILD_DIR)
	rm -rf $(BUILD_DIR)/SCalc.tar.gz
	tar -cvf $(BUILD_DIR)/SCalc.tar.gz SCalc

#------------------------ ^ Создание архивного файла ^ ------------------------

#------------------- V Генерация файла описания программы V -------------------

dvi:
	mkdir -p $(BUILD_DIR)
	makeinfo -o $(BUILD_DIR)/doc_calc --html --no-warn --force $(SRC_DIR)/calc_info.texi
	$(OPEN) $(BUILD_DIR)/doc_calc/index.html

#------------------- ^ Генерация файла описания программы ^ -------------------	

#------------------------ V Создание файла библиотеки V -----------------------

# ar - программа (сокр. от archiver - архиватор) для создания статических 
#       библиотек. Она используется для создания, модификации и просмотра 
#       объектных файлов в статических библиотеках, которые в действительности
#       представляют из себя простые архивы.
# c - заставляет создавать (от create) библиотеку, если ее нет.
# r - (от replace) заменяет старые объектные файлы новыми версиями.
# Программа ranlib добавит индекс к архиву и получится полноценная статическая
#       библиотека объектных файлов.
# $@ - подставляет название цели
# $< - подставляет зависимости (разобрать отличие от $^)
# $^ - подставляет зависимости (разобрать отличие от $<)

s21_smart_calc.a:
	gcc $(CFLAGS_LIBS) -c SCalc/*.c 
	ar rcs $@ *.o
	ranlib $@
	rm -f *.o

#------------------------ ^ Создание файла библиотеки ^ -----------------------

#------------------------------ V Тестирование V ------------------------------

# 1. Создание файла с тестами, которые будут проходить по коду и показывать
#    покрытие кода. Создание файла происходит с помощью библиотеки check.h.
#    Создание файла tests.c для модульного тестирования на языке C с
#    использованием библиотеки check.h.
# clean_mode=1 - checkmk не размещает соответствующие директивы #line в
#    исходном коде.	
# 2. Создание исходных (объектных) файлов для запуска проверки покрытия кода
# --coverage == -fprofile-arcs -ftest-coverage (при компиляции) и -lgcov
#    (при связывании (линковке)) синонимы.
# --coverage - создаёт файл *.gcno, который содержит базовую информацию для
#    запуска Code Coverage (покрытие кода).
# 3. Теперь надо запустить программу
#                            (Win: tests\tests.exe, в Unix: ./tests/tests.out).
# 4. После завершения программы, создаётся файл *.gcda, который содержит 
#    информацию о фактическом покрытии кода.
# -r . - где искать исходные файлы с информацией о фактическом покрытии кода 
# 5. Составление отчёта о Code Coverage в формате *.html с помощью
# 5.1 gcov: gcov_report
# 5.2 lcov: lcov_report
#    5.2.1 Сбор информации:
#    lcov -t "tests/tests.out" -o report_lcov.info -c -d . --rc \
#       lcov_branch_coverage=1
# -t <name> - устанавливает имя отчёта, при измерении покрытия кода тестами
#    можно указать имя теста или набора тестов.
# -o <name> - устанавливает имя выходного файла с промежуточной информацией
# -c - указывает, что lcov должен использовать существующие данные о coverage
# -d <path> - устанавливает каталог, в котором надо искать данные о coverage,
#    и мы передаём текущий каталог “.”
# --rc lcov_branch_coverage=1 - получения отчёта с информацией о \
#       выборе ветвлений
#    5.2.2 Генерация отчёта в виде HTML-страницы:
#    genhtml -o report tests.info --rc lcov_branch_coverage=1
# -o <path/nameDir> - имя каталога куда будет сложен сформированный html-отчёт
# отчёт lcov для стандартной сборки

test.c:
	@checkmk $(REMOVE_DIRECTIVES) $(TEST_DIR)/tests > $(TEST_DIR)/tests.c

tests: test.c
#	@$(CC) $(FLAGS) --coverage SCalc/*.c $(TEST_DIR)/tests.c -o $(TEST_DIR)/tests.out \
#	-lm -lcheck  $(CFLAGS_LIBS)
#	@$(CC) $(FLAGS) $(SRC_DIR)/*.c $(TEST_DIR)/tests.c --coverage -o $(TEST_DIR)/tests.out \
#	 $(CFLAGS_LIBS)
	@$(CC) $(FLAGS) $(SRC_DIR)/*.c $(TEST_DIR)/tests.c $(TEST_FLAGS) -o $(TEST_DIR)/tests.out
	@./$(TEST_DIR)/tests.out
	@mkdir -p $(TEMP_DIR)
	@mv $(TEST_DIR)/*.gcda $(TEMP_DIR)
	@mv $(TEST_DIR)/*.gcno $(TEMP_DIR)

gcov_report: tests
	@mkdir -p $(REPORT_DIR_GCOV)
	@mv $(TEMP_DIR)/*.gcda $(REPORT_DIR_GCOV)
	@mv $(TEMP_DIR)/*.gcno $(REPORT_DIR_GCOV)
	@rm -fR $(TEMP_DIR)
	@gcovr -r $(REPORT_DIR_GCOV) -r . --html-details -o test_report_gcov.html
	@mv test_report_gcov.* $(REPORT_DIR_GCOV)
	open $(REPORT_DIR_GCOV)/test_report_gcov.html

lcov_report: tests
	@mkdir -p $(REPORT_DIR_LCOV)
	@mv $(TEMP_DIR)/*.gcda $(REPORT_DIR_LCOV)
	@mv $(TEMP_DIR)/*.gcno $(REPORT_DIR_LCOV)
	@rm -fR $(TEMP_DIR)
	@lcov -t $(TEST_DIR)/tests.out -o $(REPORT_DIR_LCOV)/t_lcov.info -c -d . \
	$(BRANCH_INFO)
	@genhtml -o $(REPORT_DIR_LCOV) $(REPORT_DIR_LCOV)/t_lcov.info \
	$(BRANCH_INFO)
	open $(REPORT_DIR_LCOV)/index.html

#------------------------------ ^ Тестирование ^ ------------------------------

#-------------------------------- V Очистка V ---------------------------------

# -f Удалить файлы без подтверждения, независимо от разрешений файла. Если файл
#       не существует, не отображайть диагностическое сообщение и не изменяйте
#       статус выхода, чтобы отразить ошибку. Опция переопределяет все
#       предыдущие опции -i.
# -r Удалить папку без подтверждения.
# -v Выведет имена удаляемых файлов.
# @ в начале команды, не отображает команду в терминале.

clean: clean_dest clean_debug clean_lib clean_test clean_dvi clean_valgrind
	@rm -f *.out
	@rm -Rf report
	@rm -f o.o

clean_dest:
	@rm -fR $(BUILD_DIR)

clean_debug:
	@rm -fR o.o.dSYM tests.out.dSYM

clean_lib:
	@rm -f *.o *.a

clean_test:
	@rm -rf $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda $(TEST_DIR)/tests.c $(TEST_DIR)/tests.out
	@rm -f tests_lcov.info
	@rm -Rf $(TEMP_DIR)
	@rm -Rf $(TEST_DIR)/report_gcov
	@rm -rf $(TEST_DIR)/report_lcov

clean_dvi:
	@rm -fR doc_calc

clean_valgrind:
	@rm -f report.txt

#-------------------------------- ^ Очистка ^ ---------------------------------

#----------------------------- V Проверка кода V ------------------------------

# leaks - утечки
# Флаги для cppcheck
#   -q не показывать отчёты по проверке.
#   --enable=all - включаются дополнительные проверки. Идентификаторы:
#   * all - включаются все проверки. Рекомендуется использовать --enable=all
#       только при сканировании всей программы, потому что она включает
#       проверки unusedFunction.
#   * unusedFunction - проверка неиспользуемых функций. Рекомендуется включать
#       тогда, когда сканируется вся программа.

check:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(SRC_DIR)/*.c
	clang-format -i $(SRC_DIR)/*.h
	clang-format -n $(SRC_DIR)/*.c
	clang-format -n $(SRC_DIR)/*.h
	rm -f .clang-format

leaks: clean tests
	$(LEAK_CHECK)

cppcheck:
	cppcheck $(SRC_DIR)/*.c $(SRC_DIR)/*.h

#----------------------------- ^ Проверка кода ^ ------------------------------

#------------------------------- V Разработка V -------------------------------

vivod:
	echo "Вывод"
	echo "$(OS_NAME)"
	echo "$(BRED)"

calc: clean
	@$(CC) $(CFLAGS) $(CFLAGS_LIBS) *.c -o o.o -g -lm
	@./o.o

prob: clean
	@$(CC) $(CFLAGS) probnie/prob.c -o o.o
	@./o.o "cos(60)+(22/(3+2)*5.5+sin(30)-2+.3)/2."

struct_1: clean
	@$(CC) $(CFLAGS) struct_1.c -o o.o
	@./o.o

struct_2: clean
	@$(CC) $(CFLAGS) struct_2.c -o o.o
	@./o.o
	
struct_3: clean
	@$(CC) $(CFLAGS) struct_3.c -o o.o
	@./o.o

#------------------------------- ^ Разработка ^ -------------------------------

# Флаги и программы используемые при компиляции, линковке и тестировании
# https://runebook.dev/ru/docs/gcc/instrumentation-options
#
# Компиляция для покрытия кода
# https://gcovr.com/en/stable/guide/compiling.html#compiler-options
#
# Документация по valgrind
# https://valgrind.org/docs/manual/manual.html
#
# Раскраска вкладок (таблица стилей)
# https://www.youtube.com/watch?v=7kQ24s05gDk
