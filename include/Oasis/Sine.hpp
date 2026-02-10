//
// Created by Andrew Nazareth on 9/19/25.
//

#ifndef OASIS_SINE_HPP
#define OASIS_SINE_HPP

#include "Expression.hpp"
#include "UnaryExpression.hpp"

namespace Oasis {

template <typename OperandT = Expression>
class Sine final : public UnaryExpression<Sine, OperandT> {
public:
    Sine() = default;
    Sine(const Sine& other)
        : UnaryExpression<Sine>(other)
    {
    }

    explicit Sine(const Expression& operand)
        : UnaryExpression<Sine>(operand)
    {
    }

    [[deprecated]] [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> override 
    { 
        return nullptr;
    };

    [[nodiscard]] auto Differentiate(const Expression& var) const -> std::unique_ptr<Expression> override {
        return nullptr;
     };

    [[nodiscard]] auto Integrate(const Expression& var) const -> std::unique_ptr<Expression> override {
        return nullptr;
     };

    EXPRESSION_TYPE(Sine)
    EXPRESSION_CATEGORY(UnExp)
};

} // Oasis

#endif // OASIS_SINE_HPP
