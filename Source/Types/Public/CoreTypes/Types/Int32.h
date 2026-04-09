#ifndef CORETYPES_TYPES_INT32_H_
#define CORETYPES_TYPES_INT32_H_

#include "ValueType.h"

#include <concepts>
#include <cstdint>
#include <type_traits>

namespace CoreTypes
{
namespace Types
{
template <typename WrappedType>
    requires std::integral<WrappedType>
class NumberWrapper final
{
  public:
    constexpr NumberWrapper(WrappedType value) : m_value(value)
    {
    }
    ~NumberWrapper() = default;

    NumberWrapper& operator=(NumberWrapper&&) = default;
    NumberWrapper(const NumberWrapper&) = default;
    NumberWrapper(NumberWrapper&&) = default;

    [[nodiscard]] constexpr NumberWrapper& operator+=(
        NumberWrapper& rhs)
    {
        this->m_value += rhs.m_value;

        return *this;
    }

    [[nodiscard]] constexpr NumberWrapper& operator-=(
        NumberWrapper& rhs)
    {
        this->m_value -= rhs.m_value;

        return *this;
    }

    [[nodiscard]] constexpr NumberWrapper& operator*=(
        NumberWrapper& rhs)
    {
        this->m_value *= rhs.m_value;

        return *this;
    }

    [[nodiscard]] constexpr NumberWrapper& operator/=(
        NumberWrapper& rhs)
    {
        this->m_value /= rhs.m_value;

        return *this;
    }

    [[nodiscard]] constexpr bool operator==(NumberWrapper& rhs) const
    {
        return this->m_value == rhs.m_value;
    }

    [[nodiscard]] constexpr bool operator!=(NumberWrapper& rhs) const
    {
        return this->m_value != rhs.m_value;
    }

    [[nodiscard]] constexpr NumberWrapper operator+(
        NumberWrapper& rhs) const
    {
        return NumberWrapper(this->m_value + rhs.m_value);
    }

    [[nodiscard]] constexpr NumberWrapper operator-(
        NumberWrapper& rhs) const
    {
        return NumberWrapper(this->m_value + rhs.m_value);
    }

    [[nodiscard]] constexpr NumberWrapper operator*(
        NumberWrapper& rhs) const
    {
        return NumberWrapper(this->m_value * rhs.m_value);
    }

    [[nodiscard]] constexpr NumberWrapper operator/(
        NumberWrapper& rhs) const
    {
        return NumberWrapper(this->m_value / rhs.m_value);
    }

    [[nodiscard]] constexpr NumberWrapper& operator=(
        const NumberWrapper& rhs)
    {
        this->m_value = rhs.m_value;
        return *this;
    }

    [[nodiscard]] constexpr std::int32_t GetRaw() const
    {
        return m_value;
    }

  private:
    WrappedType m_value;
};

using Int32 = NumberWrapper<std::int32_t>;
} // namespace Types
} // namespace CoreTypes
#endif // CORETYPES_TYPES_INT32_H_