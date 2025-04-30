#ifndef UTIL
#define UTIL

inline static int isAlphaNum(char *l) {
	int c = (int)*l;
    return (c >= 48 && c <= 57) || // 0-9
           (c >= 65 && c <= 90) || // a-z
           (c >= 97 && c <= 122);  // A-Z
}

inline static int isAlpha(char *l) {
	int c = (int)*l;
    return (c >= 65 && c <= 90) || // a-z
           (c >= 97 && c <= 122);  // A-Z
}

static int isNum(char *l) {
	int c = (int)*l;
    return c >= 48 && c <= 57;   // 0-9
}

#endif
