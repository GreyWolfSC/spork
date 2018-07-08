#ifndef _GETTEXT_H_
#define _GETTEXT_H_

#ifdef __cplusplus
extern "C"
{
#endif

	bool gettextLoadLanguage(const char* langFile);
	void gettextCleanUp(void);
	/*
	 * input msg = a text in ASCII
	 * output = the translated msg in utf-8
	 */
	const char *__gettext(const char *msg);
#define tr(s) __gettext(s)
#define trNOOP(s) (s)

#ifdef __cplusplus
}
#endif

#endif /* _GETTEXT_H_ */
