#pragma once

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <string>

namespace se
{

class Log {
public:
	static inline void d(const std::string &fmt, ...)
	{
		#ifdef SHITY_DEBUG
		fprintf(stderr, "\033[0m");
		va_list va;
		va_start(va, fmt);
		log(stdout, "[DBG] " + fmt, va);
		va_end(va);
		#endif
	}

	static inline void i(const std::string &fmt, ...)
	{
		fprintf(stderr, "\033[0m");
		va_list va;
		va_start(va, fmt);
		log(stdout, "[INF] " + fmt, va);
		va_end(va);
	}

	static inline void w(const std::string &fmt, ...)
	{
		fprintf(stderr, "\033[0;33m");
		va_list va;
		va_start(va, fmt);
		log(stdout, "[WRN] " + fmt, va);
		va_end(va);
		fprintf(stderr, "\033[0m");
	}

	static inline void e(const std::string &fmt, ...)
	{
		fprintf(stderr, "\033[0;31m");
		va_list va;
		va_start(va, fmt);
		log(stderr, "[ERR] " + fmt, va);
		va_end(va);
		fprintf(stderr, "\033[0m");
	}

private:
	static inline void log(FILE *f, const std::string &fmt, va_list va)
	{
		vfprintf(f, (fmt + "\n").c_str(), va);
	}
};

}