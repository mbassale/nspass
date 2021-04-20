//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "../Category.h"
#include "../Group.h"
#include "../Password.h"
#include <boost/signals2.hpp>

namespace NSPass::Signals {

	typedef boost::signals2::connection SignalConnection;

	typedef boost::signals2::signal<void(const CategoryPtr&)> CategorySignal;

	typedef boost::signals2::signal<void(const GroupPtr&)> GroupSignal;

	typedef boost::signals2::signal<void(const PasswordPtr&)> PasswordSignal;

	class SignalContext : private boost::noncopyable {
	public:
		SignalContext() = default;

		CategorySignal& get_category_created() { return category_created_signal; }
		CategorySignal& get_category_updated() { return category_updated_signal; }
		GroupSignal& get_group_created() { return group_created_signal; }
		GroupSignal& get_group_updated() { return group_updated_signal; }
		GroupSignal& get_group_deleted() { return group_deleted_signal; }
		PasswordSignal& get_password_created() { return password_created_signal; }
		PasswordSignal& get_password_updated() { return password_updated_signal; }
		PasswordSignal& get_password_deleted() { return password_deleted_signal; }

	protected:
		CategorySignal category_created_signal{};
		CategorySignal category_updated_signal{};
		GroupSignal group_created_signal{};
		GroupSignal group_updated_signal{};
		GroupSignal group_deleted_signal{};
		PasswordSignal password_created_signal{};
		PasswordSignal password_updated_signal{};
		PasswordSignal password_deleted_signal{};
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
