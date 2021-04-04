//
// Created by Marco Bassaletti on 24-03-21.
//

#ifndef OWNPASS_CANNOTUNDOEXCEPTION_H
#define OWNPASS_CANNOTUNDOEXCEPTION_H

#include "../ApplicationException.h"

namespace NSPass::Commands {
	class CannotUndoException : public ApplicationException {
	public:
		explicit CannotUndoException() : ApplicationException("Cannot undo this command.") {}
	};
}

#endif //OWNPASS_CANNOTUNDOEXCEPTION_H
