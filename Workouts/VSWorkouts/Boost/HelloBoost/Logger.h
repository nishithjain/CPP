/*
* Logger.h
*
*  Created on: 2011-01-17
*      Author: jarrett
*/

#ifndef LOGGER_H_
#define LOGGER_H_

#include <map>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

using namespace logging::trivial;

namespace dhlogging {
	class Logger {

	public:
		static Logger* getInstance(std::string logFile = "default.log");

		void logInfo(std::string message);
		void logDebug(std::string message);
		void logWarn(std::string message);
		void logError(std::string message);
		void logFatal(std::string message);


	private:
		Logger(std::string fileName);
		Logger(Logger const&);
		Logger& operator=(Logger const&);
		virtual ~Logger();

		void initialize(std::string fileName);

		src::severity_logger< severity_level > log_;

		static Logger* logger_; // singleton instance
	};
}
#endif /* LOGGER_H_ */