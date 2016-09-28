 // Copyright comment

#pragma once

#include <iostream>
    #include <vector>
  #include <cstdint>
#include <string>

// Indented preprocessor statements
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

// Namespaces
namespace test {

// Using expressions

/// @ingroup finite_field_layers
    ///
    /// @brief Template alias for the common set of finite field
///        layers used in most stacks
template<class Field, class SuperCoder>
using finite_field_layers =
            finite_field_math<typename fifi::default_field<Field>::type,
        // Test comment
    finite_field<Field, SuperCoder>>;

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
        // Test comment
            kodo_core::uniform_generator_layers::type<Features,
                kodo_core::pivot_aware_generator<
                    SuperCoder> > >;

// Expression with template disambiguator
using type = typename std::conditional<
    Predicate<T>::value,
        typename conditional_append<Predicate,
      typename TypeList::template append<T>, List...>::type,
         typename conditional_append<Predicate,
       TypeList, List...>::type>::type;

// Template stacks

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

template<class T>
struct is_regular :
    // Comment 2
        std::integral_constant<bool,
        // Comment 3
        std::is_default_constructible<T>::value &&
    // Comment 4
    std::is_move_assignable<T>::value>
    { };

class client : public
    links::message_handler<links::message,
    message_printer<
    links::link
    >>
{
protected:

    /// Helper struct to determine if two classes have the same field types
    template<class T>
    struct is_same_field {
        static const bool value =
        std::is_same<typename T::field_type, field_type>::value;
    };
    };

}

// Nested namespaces
namespace test
{

namespace api {
inline std::shared_ptr<final_interface> build(final_interface* stack)
{
    auto api = dynamic_cast<build_interface*>(stack);
        assert(api);
    return api->build( );
}
}

namespace
{
struct dummy_one
{
    template<class Factory>
        void construct(Factory& the_factory)
    {
            (void) the_factory;
        m_construct();
    }

    stub::function<void()> m_construct;
};
}

}

// Free functions

/// @copydoc layer::multipy_add(uint8_t*, const uint8_t*,
///                             value_type, uint32_t)
void multiply_add(uint8_t* symbol_dest,
                    const uint8_t* symbol_src,
         value_type coefficient, uint32_t symbol_size)
{
    assert (m_field);
        assert(symbol_dest != 0);
    assert( symbol_src != 0);
    assert(symbol_size > 0);

    coefficient = fifi::pack_constant<field_type>(coefficient);

    m_field->region_multiply_add(symbol_dest, symbol_src, coefficient,
                                    symbol_size);
}

    template<typename U>
static auto test(int) ->
decltype(std::declval<U>().some_function(), yes());

template<class SuperCoder>
inline auto
vandermonde_matrix_base::config::construct_matrix(uint32_t symbols) ->
        std::shared_ptr<generator_matrix>
{
        // Something
}

template<
    class Field,
        class TraceTag
    >
auto coder(const std::string& name) ->
    boost::python::class_<Coder<Field, TraceTag>, boost::noncopyable>
    {
    // Something
    }

template<std::size_t... Is, class F, class... Args>
inline auto easy_bind(indices<Is...>, F const& f, Args&&... args) ->
decltype(std::bind(
        f, std::forward<Args>(args)..., placeholder<Is + 1> {} ...))
{
return std::bind(
        f, std::forward<Args>(args)..., placeholder<Is + 1> {} ...);
}

template<class R, class... FArgs, class... Args>
inline auto easy_bind(std::function<R(FArgs...)> f, Args&&... args) ->
    decltype(detail::easy_bind(
            detail::build_indices<sizeof...(FArgs) - sizeof...(Args)> {},
        f, std::forward<Args>(args)...))
{
    return detail::easy_bind(
            detail::build_indices<sizeof...(FArgs) - sizeof...(Args)> {},
        f, std::forward<Args>(args)...);
}

    template <typename R, typename T, typename... FArgs, typename... Args>
inline auto easy_bind(R(T::*mf)(FArgs...), Args&&... args) ->
    decltype(detail::easy_bind(
        detail::build_indices<(sizeof...(FArgs) + 1) - sizeof...(Args)>(),
            mf, std::forward<Args>(args)...))
{
    // The extra argument is the object pointer (this)
    static_assert(sizeof...(Args) <= sizeof...(FArgs) + 1,
            "Too many arguments to easy_bind");

    return detail::easy_bind(
        detail::build_indices<(sizeof...(FArgs) + 1) - sizeof...(Args)>(),
            mf, std::forward<Args>(args)...);
}

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

template
    <
    typename... Types,
    // Comment 1
        typename I = std::make_index_sequence<
        // Comment 2
        std::tuple_size<std::tuple<Types...>>::value>
    >
constexpr auto tuple_to_array(std::tuple<Types...>&& tuple);


#ifdef __cplusplus
extern "C"
{
#endif

KODOC_API
    uint8_t kodoc_has_write_payload(kodoc_coder_t coder);

KODOC_API
void kodoc_set_mutable_symbols(
 kodoc_coder_t decoder, uint8_t* data, uint32_t size);

#ifdef __cplusplus
}
#endif

namespace fifi
{
#ifdef PLATFORM_AVX2

namespace detail
{
inline void multiply_helper(__m256i &low, __m256i& high,
             __m256i* &table_ptr, __m256i& sum)
{
    __m256i table1, table2;
    __m256i h, l, product;

    // Load the 32-byte row that contains the pre-calculated
    // multiplication results with the low-half of the constant
    table1 = _mm256_loadu_si256(table_ptr++);
}
}

#else

avx2_binary8_full_table::avx2_binary8_full_table()
{
    (void) m_table_one;
    (void) m_table_two;
}

void avx2_binary8_full_table::region_add(
    uint8_t*, const uint8_t*, uint32_t ) const
    {
    // Not implemented
    assert(0 && "This line should never be executed");
}

#endif
}

// Enum
enum error_type
{
        failed_open_file = 1,
    failed_open_file = 2
    };

// Normal class
class my_class {
public:

    // Constructors

    my_class(): m_first(0U),
        m_second(1U)
    { }

    my_class()
        : m_vector { 1, 2, 3, 4 },
            m_second(1U)
    { }

    // Make sure that this base class cannot be instantiated
    factory(kodoc_factory_t factory,
            std::function<void(kodoc_factory_t)> deleter)
        : m_factory(factory, deleter)
    { }

    decoder_factory(codec codec, field field,
                    uint32_t max_symbols, uint32_t max_symbol_size):
        factory(kodoc_new_decoder_factory(
            (int32_t)codec, (int32_t)field, max_symbols, max_symbol_size),
        [](kodoc_factory_t factory) { kodoc_delete_factory(factory); })
    { }

    io_service() :
        m_io_service(
            score_new_io_service(), [](score_io_service_t io) {
            score_delete_io_service(io);
        })
    { }

    io_service() :
        m_io_service(
            score_new_io_service(),
            {
            1, 2, 3
            })
    { }

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

public:

    // Function calls
    void function_calls() {
        srand( static_cast<uint32_t>( time(0 ) ));

        assert(m_socket && "Invalid socket in queue_async_receive");

        assert(cancelled == 0 &&
           "Rate limiter send called multiple times without "
               "waiting for callback!");

        m_timer->async_wait(std::bind(&rate_limiter::timeout_handler,
                       this, std::placeholders::_1, callback));

        namespace ph = std::placeholders;

        m_socket->async_receive_from(
            boost::asio::buffer(m_receive_buffer), *ep, std::bind(
                &sockets::handle_async_receive_from, this,
            ph::_1, ph::_2, ep));

        m_redundancy_estimator.sample(
                (1.0 + m_redundancy_estimator.estimate()) *
            m_generation_size() / m_worst.get() - 1.0);

        m_formatters.insert(std::make_pair(
                "csv", std::shared_ptr<tables::format>(new tables::csv_format())),
            third_param);

        EXPECT_TRUE(main_stack->copy_from_symbols.expect_calls().with(
            storage::storage(data))
                .to_bool());

        // Before function
        m_socket->async_receive_from(
            // Line 1
            looooooooooooooooong_function_name1(m_receive_buffer),
        // Line 2
        { 1, 2, 3, 4 },
            // Line 3
            looooooooooooooooong_function_name2(
                    // Line 4
                &sockets::handle_async_receive_from, this,
                    ph::_1, ph::_2, ep));


        // Initializer block within a function call
        m_output_queue.insert(m_output_queue.begin(),
                                            vector { 1, 2, 3 });

        m_output_queue.insert(m_output_queue.begin(),
                    {
                        1, 2, 3
                    },
                              more);

        m_output_queue.insert(
            {
            1, 2, 3
            },
                m_output_queue.end());

        std::map<uint32_t, uint32_t> generation_map(
        { {0, 100}, {1, 100}, {2, 100}, {3, 10}, {4, 10} });

        std::map<uint32_t, uint32_t> generation_map(
        {
                {0, 100}, {1, 100},
            {2, 100}, {3, 10},
                {4, 10}
            });

        // Examples for non-optimal manual layout. The lines should be broken
        // after the '(' to get decent layout.
        score::generation_storage_in::coder_type::factory factory(symbol_size,
                                       generation_size);

        boost::asio::ip::multicast::join_group option(addr,
                        score::manual_sender::address_type());
    }

    // Assignments and arithmetics
    void assignments()
    {
        m_pep = m_pep * std::pow(base, losses + 1.0) +
                        (1.0 - std::pow(base, losses));

        m_worst =
                    (m_worst) ? std::max(*m_worst, s.m_rank) : s.m_rank;

        bool binary_ext_fields =
                std::is_same<field_type, fifi::binary4>::value ||
            std::is_same<field_type, fifi::binary8>::value;

        double time = static_cast<double>(
                    boost::chrono::duration_cast<boost::chrono::microseconds>(
                m_total_stop-m_total_start).count());

        statistics iter = calculate_statistics(iterations.cbegin(),
                                                    iterations.cend());

        bool result = std::equal(input_buffer.begin(), input_buffer.end(),
                          output_buffer.begin());

        m_socket->async_receive_from(
                    looooooooooooooooong_function_name1(alpha) <
            looooooooooooooooong_function_name2(beta));

        std::shared_ptr<endpoint_type> ep =
        std::make_shared<endpoint_type>();

        using rlnc_decoder = kodo_rlnc::full_vector_decoder<
                       fifi::binary, fifi::binary4, fifi::binary8>;

        uint8_t constant_matrix[3][3] =
            {
            {1, 2, 3},
                    {5, 6, 7},
                {53, 71, 42}
        };

        expected_coefficients =
            { 95, 203, 243, 46, 187, 199, 153, 152, 39, 114 };

        EXXXXXXXXECT_EQ(1u, stack.m_send.calls()) <<
                "Only one packet be send as " <<
                "io service is not run yet";

        out << "\t\t" << "dest = " << ((uintptr_t) std::get<0>(v))
                    << " src = " << ((uintptr_t) std::get<1>(v))
            << " length = " << ((uint32_t) std::get<2>(v)) << std::endl;

        std::cout << "This is a very looooooong line for this Hello World! " <<
            "string string" << num << std::endl;
    }

    // Return statements
    void return_statements() {
        return  m_pep * std::pow(base, losses + 1.0) +
                        (1.0 - std::pow(base, losses));

        return looooooooooooooooong_function_name(
                        alpha + beta);

        return detail::easy_bind(
                    detail::build_indices<sizeof...(Args)>(),
            mf, std::forward<Args>(args)...);
    }


    // Control flow and special blocks
    void blocks()
    {
        {
            max_value = *std::max_element(std::begin(m_container),
                                  std::end(m_container));

            m_redundancy_estimator.sample(
                (1.0 + m_redundancy_estimator.estimate()) *
                m_generation_size() / m_worst.get() - 1.0);

            bool alpha = beta +
                                gamma;

            return beta +
                gamma;
        }

        if (coffee_pot == full &&
                second_condition::value &&
                third_condition::value)
        {
                continue;
        }

        while (foundAssignmentOp->length() <
            foundNonAssignmentOp->length())
        {
        foundAssignmentOp = NULL;
        }

        for (const auto & item : m_snack_list )
        {
            item.write(writer, m_current_generation);
        }

        for ( auto it = stored_snacks.lower_bound(feedback_generation - rtt);
             it != stored_snacks.end();++it) {
              lowest_rank = std::min(it->second, lowest_rank);
        }

        switch (other.m_type) {
            case class_type::object:
            m_internal.m_map =
                new json::object_type(
                    other.m_internal.m_map->begin(),
                    other.m_internal.m_map->end());
            break;
        default:
                // Something
                break;
            }

        try {
            my_function();
        }
        catch(const std::exception& e)
        {
                    // handles std::exception
        }
        catch(...)
        {
            // handles int or std::string or any other unrelated type
        }

        // Alignment for commas
        int a, b, c,
                        d, e, f;

        // This is a block with an arbitrary macro header
        RUN
        {
            max_value = *std::max_element(std::begin(m_container),
                                                std::end(m_container));

            m_redundancy_estimator.sample(
                (1.0 + m_redundancy_estimator.estimate()) *
                        m_generation_size() / m_worst.get() - 1.0);

                bool alpha = beta +
                         gamma;

                return beta +
                   gamma;
        }
    }


    // Lambda functions
    void lambda_functions()
    {
        // Standalone lambdas

        auto recycle = [&recycled](std::shared_ptr<dummy_two> o) {
            EXPECT_TRUE((bool) o);
            ++recycled;
        };

        auto callback = [function](const std::string& zone,
                              const std::string& message)
        {
            boost::python::call<void>(function, zone, message);
        };

        auto callback = [function](
                    const std::string& zone, const std::string& message)
        {
            boost::python::call<void>(function, zone, message);
        };

        auto compare = [](const parameter& a, const parameter& b) -> bool {
            if(std::get<0>(a) != std::get<0>(b))
                return false;
        };

        // Single-line lambdas

        std::function<uint32_t()> m_delay_generator =
        []() { return 0; };

        m_output_queue.insert(m_output_queue.begin(),
                     queue_item(repair, []() {}));

        std::generate(data.begin(), data.end(),
                                [&]() { return randval(engine); });

        in.fetch_data_ready(
        [&](std::vector<uint8_t>& cb) { fetch_data_ready_stub(cb); });

        // Lambda blocks as function arguments

        sender.flush([&io]() {
            io.stop();
                std::cout << "IO service stopped." << std::endl;
        });

        s.write_data(buffer, [&]()
        {
                    io.post(write_data_callback);
        });

        m_io_thread = std::make_shared<std::thread>([&] {
            m_io_service.run();
        });

        auto cmp = stub::make_compare( [](const cup& c)->bool
        {
            return c.m_volume == 2.3;
        });

        // Lambda within a lambda

        deleter = []( kodoc_factory_t factory)   {
            kodoc_delete_factory(factory);

            auto recycle = [&recycled](std::shared_ptr<dummy_two> o)
            {
                EXPECT_TRUE((bool) o);
                ++recycled;
            };
        }
    }

    // Standalone template expressions
    void standalone_templates()
    {
        run_test_basic_api<
                    // Line 1
                Encoder<fifi::binary>,
            // Line 2
                Decoder<fifi::binary>
        >(  symbols, symbol_size);

        parser<
                    box::moov<parser<
                box::trak<parser<
                    box::mdia<parser<
                                box::hdlr,
                            box::mdhd
                    >>
                >>
            >>
        > parser;

        {
                SCOPED_TRACE(testing::Message() << "field = binary");
            run_test_basic_api<
                    Encoder<fifi::binary>,
                // Line 2
                Decoder<fifi::binary>
                >(symbols, symbol_size);
        }
    }


    protected:

    // Member variables

    std::function<void(const std::vector<uint8_t>&)> m_write_symbol_callback;

    stub::function<uint32_t, const storage::const_storage> copy_into_symbol;

    stub::function<
        void(uint8_t**, const uint8_t**, uint8_t**, uint32_t, uint32_t)
        > m_vector_dot_product;

    stub::function<
        void (uint8_t*, const uint8_t*, value_type, uint32_t)
            > multiply_add;
    };

// gtest macros

    INSTANTIATE_TEST_CASE_P(/* symbol_size */,
                        test_message_serialize_parse_param,
                                ::testing::Values(/*4u, 10U, 15U, 30U,*/
                            150U, 300U, 500U,
                            1500U, 3000U, 5000U));

INSTANTIATE_TEST_CASE_P (
/* symbol_size */,
test_message_serialize_parse_param,
::testing::Values(
    /*4u, 10U, 15U, 30U,*/
    150U, 300U, 500U,
    1500U, 3000U, 5000U));

// Main function body

int main(int argc, const char *argv[])
{
    uint16_t num = 42;

    auto recycle = [&recycled](std::shared_ptr<dummy_two> o)
        {
            EXPECT_TRUE((bool) o);
            ++recycled;
        };

    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    std::vector<uint8_t> data = {
        0x67, 0x42, 0x00, 0x0A, 0xF8, 0x41, 0xA2
    };

    // insert code here...
    std::cout << "This is a very loooooooooong line for this Hello World! "
                    << num << std::endl;

    for (int &i : v)
            std::cout << i << ' ';

    return 0;
}
