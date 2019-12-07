all: gitbook


gitbook:
	 gitbook pdf
	 mv book.pdf dPatterns.pdf
