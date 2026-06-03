#pragma once

namespace jmaths {
    namespace utility {

        struct Range
        {
            float min = 0;
            float max = 10;
            float step = 0.1f;
        };

        inline Range range(float min, float max, float step = 0.1f)
        {
            return { min, max, step };
        }

        inline Range range(float sample)
        {
            return { 0, sample, 0.1};
        }
    }
}
