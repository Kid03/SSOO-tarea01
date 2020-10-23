SRC=src

all:
	@cd $(SRC) && make

clean:
	@cd $(SRC) && make clean
	@cd ..
	@rm -f hora *~

distclean: clean
	@cd $(SRC) && make distclean

.PHONY: all clean distclean

