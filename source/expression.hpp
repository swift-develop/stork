#ifndef expression_hpp
#define expression_hpp

#include "runtime_context.hpp"

#include <string>

namespace stork {
	template <class T>
	class expression {
		expression(const expression&) = delete;
		void operator=(const expression&) = delete;
	protected:
		expression() = default;
	public:
		using ptr = std::unique_ptr<const expression>;
		
		virtual T evaluate(runtime_context& context) const = 0;
		virtual ~expression() = default;
	};
	
	using void_expression = expression<void>;
	using number_expression = expression<number>;
	using string_expression = expression<string>;
	using array_expression = expression<array>;
	using function_expression = expression<function>;
	using variable_expression = expression<variable_ptr>;
	using number_variable_expression = expression<number_variable_ptr>;
	using string_variable_expression = expression<string_variable_ptr>;
	using array_variable_expression = expression<array_variable_ptr>;
	using function_variable_expression = expression<function_variable_ptr>;
}

#endif /* expression_hpp */