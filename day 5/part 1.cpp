#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

struct Mapping {
    uint32_t dst_range_start;
    uint32_t src_range_start;
    uint32_t range_len;
};

struct Range {
    uint32_t s;
    uint32_t e;
};

struct Input {
    std::vector<uint32_t> seeds_p1;
    std::vector<Range> seeds_p2;

    std::vector<Mapping> seed_to_soil;
    std::vector<Mapping> soil_to_fertilizer;
    std::vector<Mapping> fertilizer_to_water;
    std::vector<Mapping> water_to_light;
    std::vector<Mapping> light_to_temperature;
    std::vector<Mapping> temperature_to_humidity;
    std::vector<Mapping> humidity_to_location;
};

Input input_generator(const std::string& input) {
    std::istringstream iss(input);
    std::string line;

    Input data;

    std::getline(iss, line);
    std::istringstream seeds_line(line.substr(7));
    uint32_t seed;
    while (seeds_line >> seed) {
        data.seeds_p1.push_back(seed);
    }

    std::vector<std::pair<uint32_t, uint32_t>> seed_ranges;
    while (std::getline(iss, line)) {
        if (line.empty())
            break;

        std::istringstream range_line(line);
        uint32_t dst_range_start, src_range_start, range_len;
        range_line >> dst_range_start >> src_range_start >> range_len;
        data.seeds_p2.push_back({src_range_start, src_range_start + range_len - 1});
    }

    std::vector<std::vector<Mapping>*> mapping_ptrs = {
        &data.seed_to_soil, &data.soil_to_fertilizer, &data.fertilizer_to_water,
        &data.water_to_light, &data.light_to_temperature, &data.temperature_to_humidity,
        &data.humidity_to_location
    };
    for (auto& mappings : mapping_ptrs) {
        std::getline(iss, line);
        while (std::getline(iss, line)) {
            if (line.empty())
                break;

            std::istringstream mapping_line(line);
            Mapping map;
            mapping_line >> map.dst_range_start >> map.src_range_start >> map.range_len;
            mappings->push_back(map);
        }
    }

    return data;
}

uint32_t part(const Input& input) {
    std::vector<uint32_t> state = input.seeds_p1;

    auto apply_mapping = [](const std::vector<uint32_t>& old_state, const std::vector<Mapping>& mapping) -> std::vector<uint32_t> {
        std::vector<uint32_t> result;
        for (uint32_t prev : old_state) {
            for (const Mapping& m : mapping) {
                uint32_t p = prev;
                uint32_t s = m.src_range_start;
                uint32_t l = m.range_len;
                uint32_t d = m.dst_range_start;

                if (p >= s && p < s + l) {
                    result.push_back((p - s) + d);
                    goto next_prev;
                }
            }
            result.push_back(prev);

        next_prev:
            continue;
        }
        return result;
    };

    state = apply_mapping(state, input.seed_to_soil);
    state = apply_mapping(state, input.soil_to_fertilizer);
    state = apply_mapping(state, input.fertilizer_to_water);
    state = apply_mapping(state, input.water_to_light);
    state = apply_mapping(state, input.light_to_temperature);
    state = apply_mapping(state, input.temperature_to_humidity);
    state = apply_mapping(state, input.humidity_to_location);

    return *std::min_element(state.begin(), state.end());
}

int main() {
    std::ifstream inputFile("input.txt");
    std::stringstream buffer;
    std::string input;

    if (inputFile.is_open()) {
        buffer << inputFile.rdbuf();
        inputFile.close();
        input = buffer.str();
    } else {
        std::cerr << "Error." << std::endl;
    }

    Input data = input_generator(input);

    std::cout << part(data) << std::endl;

    return 0;
}