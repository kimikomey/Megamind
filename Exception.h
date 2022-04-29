#pragma once

class Exception
{
	char* _message;
	int _line;

public:
	Exception(char* message, int line);
	~Exception();

	char* GetMessage();
	int GetLine();

	enum Exceptions
	{
		CharError,						// 0
		StringError,
		FileReaderError,
		TypeNameLengthError,
		UnknownType,
		UnknownOperation,				// 5
		MissingBracket,
		ArgumentOutOfRange,
		InvalidOperation,
		NoTree,
		TokenNotFound,					//10
		VariableNameNotFound,
		VariableTypeNotFound,
		RedefinitionVariable,
		ConstInitializationError,
		VariableInitializationError,	//15
		ArrayInitializationError,
		InitializationError,
		InvalidCharacter,
		UninitializedConstant,
		VariableNameIsNotSpecified,		// 20
		InvalidVariableName,
		ArraySizeIsNotAConstant,
		ArraySizeIsNotAnInteger,
		IndexIsNotSpecified,
		ArrayIndexIsNotAnInteger,		// 25
		ConstantReinitialization,
		SystemFunctionIsNotSupported,
		MissingArguments,
		UnexpectedEndOfFile,
	};


};

