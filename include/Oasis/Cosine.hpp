#ifndef OASIS_COSINE_HPP
#define OASIS_COSINE_HPP

#include "Expression.hpp"
#include "UnaryExpression.hpp"

namespace Oasis {

template <IExpression OperandT>
class Cosine;

template <typename OperandT = Expression>
class Cosine final :public UnaryExpression<Cosine, OperandT> {
public:
    Cosine() = default;
    Cosine(const Cosine& other)
        : UnaryExpression<Cosine>(other)
    {
    }

    explicit Cosine(const Expression& operand)
        : UnaryExpression<Cosine>(operand)
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

    EXPRESSION_TYPE(Cosine)
    EXPRESSION_CATEGORY(UnExp)
};

} // Oasis

#endif // OASIS_COSINE_HPP