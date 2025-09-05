
INCLUDER = util/includer.perl

all:
	rm -f index.html
	$(INCLUDER)  index.html.source  >  index.html
	chmod 444 index.html


