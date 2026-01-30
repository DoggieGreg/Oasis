#include "Oasis/Cosine.hpp"
#include "Oasis/Expression.hpp"
#include "Oasis/UnaryExpression.hpp"
#include <cmath>

namespace Oasis {
auto Cosine<Expression>::Simplify() const -> std::unique_ptr<Expression>
{   
    const auto simplifiedOperand = operand ? operand->Simplify() : nullptr;
    if (!operand){
        return nullptr;
    }

    // Cos(real) --> some number
    if (const auto realCase = RecursiveCast<Cosine<Real>>(simplifiedOperand); realCase != nullptr) {
        return std::make_unique<Real>(std::cos(realCase->GetOperand()));
    }

    // Cos(Arccos(x)) --> x
    // Arccos not implemented yet
    // if (auto CosArccosineCase = RecursiveCast<Cosine<Arccosine<Expression>>>(simplifiedOperand); CosArccosineCase != nullptr) {
    //     return std::make_unique<Expression>(CosArccosineCase->GetOperand().GetOperand());
    // }

    
    if (auto CosNegativeOperand = RecursiveCast<Cosine<Multiply<Real,Expression>>>(simplifiedOperand); CosNegativeOperand != nullptr) {
        const Real& multreal = CosNegativeOperand->GetOperand().GetMostSigOp();
        const Oasis::IExpression auto& multexp = CosNegativeOperand->GetOperand().GetLeastSigOp();
        
        // Cos(-x) --> Cos(x)
        if (multreal.GetValue < 0){
            return std::make_unique<Cosine<Expression>>(Multiply<Real,Expression>{Real {multreal.GetValue() * -1},multexp});
        }
        // Cos(2x) --> cos^2(x) - sin^2(x)
        // if ((multreal.GetValue % 2) == 0) {
        //     return std::make_unique<Add<Expression>>(Exponent<Expression,Real>{},Multiply<Real,Expression>{Real{-1},});
        // }
    }

    return nullptr;
}

auto Cosine<Expression>::Differentiate(const Expression&) const -> std::unique_ptr<Expression>
{
    return nullptr;
}

auto Cosine<Expression>::Integrate(const Expression&) const -> std::unique_ptr<Expression>
{
    return nullptr;
}
} // Oasis