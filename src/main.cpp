#include <benchmark/benchmark.h>
#include <vector>
#include <exception>
#include <stdexcept>

static void without_exception(benchmark::State &state){
    for (auto _ : state){
        std::vector<uint32_t> v(10000);
        for (uint32_t i = 0; i < 10000; i++) v.at(i) = i;        
    }
}
BENCHMARK(without_exception);//-----------------------------------------

static void with_exception(benchmark::State &state){
    for (auto _ : state){
        std::vector<uint32_t> v(10000);
        for (uint32_t i = 0; i < 10000; i++){
            try{
                v.at(i) = i;
            }
            catch (const std::out_of_range &oor){}
        }
    }
}
BENCHMARK(with_exception);//--------------------------------------------

static void throwing_exception(benchmark::State &state){
    for (auto _ : state){
        std::vector<uint32_t> v(10000);
        for (uint32_t i = 0; i <= 10000; i++){
            try{
                v.at(i) = i;
            }
            catch (const std::out_of_range &oor){}
        }
    }
}
BENCHMARK(throwing_exception);//-----------------------------------------

BENCHMARK_MAIN();