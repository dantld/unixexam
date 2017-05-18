.PHONY: all clean run

all :
	$(foreach dir,$(wildcard lib.[0-9a-zA-Z]*),make -C $(dir) all;)
	$(foreach dir,$(wildcard exam.[0-9][0-9]),make -C $(dir)  all;)

run :
	$(foreach dir,$(wildcard exam.[0-9][0-9]),make -C $(dir) run;)

clean :
	$(foreach dir,$(wildcard exam.[0-9][0-9]),make -C $(dir)  clean;)
	$(foreach dir,$(wildcard lib.[0-9a-zA-Z]*),make -C $(dir) clean;)
	@find . -type f -a -name \*.o   -exec rm -f {} \;
	@find . -type f -a -name \*.d   -exec rm -f {} \;
	@find . -type f -a -name \*.lis -exec rm -f {} \;
	@find . -type f -a -name \*.log -exec rm -f {} \;
