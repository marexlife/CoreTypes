#ifndef CORETYPES_INT32_H_
#define CORETYPES_INT32_H_

#include <cmath>
#include <cstdint>
#include <type_traits>

namespace CoreTypes
{
template <typename WrappedType>
    requires std::is_arithmetic_v<WrappedType>
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

    [[nodiscard]] constexpr WrappedType operator*() const
    {
        return m_value;
    }

    [[nodiscard]] constexpr WrappedType GetRaw() const
    {
        return m_value;
    }

  private:
    WrappedType m_value;
};

using Uint8 = NumberWrapper<std::uint8_t>;
using Uint16 = NumberWrapper<std::uint16_t>;
using Uint32 = NumberWrapper<std::uint32_t>;
using Uint64 = NumberWrapper<std::uint64_t>;

using Int8 = NumberWrapper<std::int8_t>;
using Int16 = NumberWrapper<std::int16_t>;
using Int32 = NumberWrapper<std::int32_t>;
using Int64 = NumberWrapper<std::int64_t>;

using Float = NumberWrapper<std::float_t>;
using Double = NumberWrapper<std::double_t>;
} // namespace CoreTypes
#endif // CORETYPES_INT32_H_