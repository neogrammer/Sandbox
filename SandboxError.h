#ifndef SANDBOXERROR_H__
#define SANDBOXERROR_H__
#include <stdexcept>
#include <string>
namespace sbx
{
	class SandboxError : public std::exception
	{
		std::string mMsg;

	public:
		SandboxError(std::string msg_) : std::exception{ msg_.c_str() }, mMsg{}
		{
			std::string msg = "Custom Exception Occurred : [";
			msg.append(msg_);
			msg.append("]");

			mMsg = msg;
		}

		const char* what() const noexcept override {
			return mMsg.c_str();
		}
	};
}

#endif