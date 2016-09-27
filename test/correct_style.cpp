#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

#if defined(PLATFORM_WINDOWS_PHONE)
    #if defined(PLATFORM_MSVC_ARM)
        // NEON introduced in VS2012
        #if (_MSC_VER >= 1700)
            #define PLATFORM_NEON 1
        #endif
    #endif
#elif defined(PLATFORM_MSVC_X86)
    // SSSE3, SSE4.1, SSE4.2, PCLMUL introduced in VS2008
    #if (_MSC_VER >= 1500)
        #define PLATFORM_SSSE3 1
        #define PLATFORM_SSE41 1
        #define PLATFORM_SSE42 1
        #define PLATFORM_PCLMUL 1
    #endif
    // AVX and AVX2 introduced in VS2012
    #if (_MSC_VER >= 1700)
        #define PLATFORM_AVX 1
        #define PLATFORM_AVX2 1
    #endif
#endif

namespace kodo_core
{
/// @ingroup finite_field_layers
///
/// @brief Template alias for the common set of finite field
///        layers used in most stacks
template<class Field, class SuperCoder>
using finite_field_layers =
    finite_field_math<typename fifi::default_field<Field>::type,
    finite_field<Field, SuperCoder>>;
}

namespace kodo_rlnc
{
/// @ingroup coefficient_generator_layers
///
/// @brief Generates an uniform random coefficient (from the
///        chosen Finite Field) for every symbol. In addition
///        using the pivot_aware_generate means that we will only
///        generate non-zero coefficients for symbols which are
///        available locally.
template<class Features, class SuperCoder>
using on_the_fly_generator =
    kodo_core::check_partial_generator<
    kodo_core::uniform_generator_layers::type<Features,
    kodo_core::pivot_aware_generator<
    SuperCoder> > >;
}

namespace kodo_rlnc
{
template
<
    class MainStack,
    class Features
>
class full_vector_recoding_stack : public
    // Payload API
    kodo_core::payload_info<
    // Codec Header API
    kodo_core::default_off_systematic_encoder<
    kodo_core::symbol_id_encoder<
    // Symbol ID API
    recoder_symbol_id<
    // Coefficient Generator API
    kodo_core::uniform_generator_layers::type<Features,
    kodo_core::pivot_aware_generator<
    // Encoder API
    kodo_core::write_symbol_tracker<
    kodo_core::zero_symbol_encoder<
    kodo_core::trace_write_symbol<kodo_core::find_enable_trace<Features>,
    kodo_core::trace_symbol<kodo_core::find_enable_trace<Features>,
    kodo_core::linear_block_encoder<
    // Coefficient Storage API
    kodo_core::coefficient_value_access<
    // Proxy
    kodo_core::proxy_layer<MainStack,
    kodo_core::final_layer
    > > > > > > > > > > > > >
{ };
}

namespace fifi
{
template
<
    class T,
    typename std::enable_if<has_region_multiply_constant<T>::value,
                            uint8_t>::type = 0
>
inline void region_multiply_constant(T& t, uint8_t* dest,
                                     typename T::value_type constant,
                                     uint32_t size)
{
    t.region_multiply_constant(dest, constant, size);
}

/// @copydoc layer::multipy_add(uint8_t*, const uint8_t*,
///                             value_type, uint32_t)
void multiply_add(uint8_t* symbol_dest,
                  const uint8_t* symbol_src,
                  value_type coefficient, uint32_t symbol_size)
{
    assert(m_field);
    assert(symbol_dest != 0);
    assert(symbol_src != 0);
    assert(symbol_size > 0);

    coefficient = fifi::pack_constant<field_type>(coefficient);

    m_field->region_multiply_add(symbol_dest, symbol_src, coefficient,
                                 symbol_size);
}
}

namespace magic
{
class my_class
{
public:

    stub::function<uint32_t, const storage::const_storage> copy_into_symbol;

    stub::function<
        void(uint8_t**, const uint8_t**, uint8_t**,
             uint32_t, uint32_t, uint32_t)
    > m_vector_dot_product;

    stub::function<
        void (uint8_t*, const uint8_t*, value_type, uint32_t)
    > multiply_add;

    my_class() :
        m_value(0U),
        m_second(1U)
    { }

    uint32_t value() const
    {
        return m_value;
    }

    void set_value(uint32_t value)
    {
        m_value = value;

        m_pep = m_pep * std::pow(base, losses + 1.0) +
                (1.0 - std::pow(base, losses));

        if (coffee_pot == full &&
            second_condition::value &&
            third_condition::value)
        {
            continue;
        }

        try
        {
            my_function();
        }
        catch (const std::exception& e)
        {
            // handles std::exception
        }
        catch (...)
        {
            // handles int or std::string or any other unrelated type
        }

        m_redundancy_estimator.sample(
            (1.0 + m_redundancy_estimator.estimate()) *
            m_generation_size() / m_worst.get() - 1.0);

        m_worst =
            (m_worst) ? std::max(*m_worst, s.m_rank) : s.m_rank;
    }

    /// Queues an async receive call on the socket
    void queue_async_receive()
    {
        assert(m_socket && "Invalid socket in queue_async_receive");

        assert(cancelled == 0 &&
               "Rate limiter send called multiple times without "
               "waiting for callback!");

        namespace ph = std::placeholders;

        m_receive_buffer.resize(receive_buffer_size, 0u);

        std::shared_ptr<endpoint_type> ep =
            std::make_shared<endpoint_type>();

        m_timer->async_wait(std::bind(&rate_limiter::timeout_handler,
                                      this, std::placeholders::_1, callback));

        m_socket->async_receive_from(
            boost::asio::buffer(m_receive_buffer), *ep, std::bind(
                &sockets::handle_async_receive_from, this,
                ph::_1, ph::_2, ep));
    }


    template
    <
        class T = Value,
        typename std::enable_if<
            std::is_default_constructible<T>::value, uint8_t>::type = 0
    >
    resource_pool() :
        m_pool(std::make_shared<impl>(
            allocate_function(std::make_shared<value_type>)))
    { }

private:

    uint32_t m_value;
};
}

/// Test that our resource pool is a regular type. We are not
/// implementing equality or less than here, but maybe we could.
namespace
{
template<class T>
struct is_regular :
    std::integral_constant<bool,
    std::is_default_constructible<T>::value &&
    std::is_copy_constructible<T>::value &&
    std::is_move_constructible<T>::value &&
    std::is_copy_assignable<T>::value &&
    std::is_move_assignable<T>::value>
{ };
}

int main(int argc, const char* argv[])
{
    uint16_t num = 42;

    auto recycle = [&recycled](std::shared_ptr<dummy_two> o)
    {
        EXPECT_TRUE((bool) o);
        ++recycled;
    };

    std::vector<uint8_t> data =
    {
        0x67, 0x42, 0x00, 0x0A, 0xF8, 0x41, 0xA2
    };

    // insert code here...
    std::cout << "This is a very loooooooooong line for this Hello World! "
              << num << std::endl;

    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    for (int& i : v)
        std::cout << i << ' ';

    return 0;
}
