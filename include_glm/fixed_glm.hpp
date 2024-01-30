#pragma once
#include "fixed.hpp"
#include "glm/glm.hpp"

#if __SIZEOF_POINTER__ >= 8
namespace glm
{
    using f8_8vec1  = vec<1, fpn::fixed8_8>;
    using f8_16vec1 = vec<1, fpn::fixed8_16>;
    using f8_24vec1 = vec<1, fpn::fixed8_24>;
    using f8_32vec1 = vec<1, fpn::fixed8_32>;
    using f8_40vec1 = vec<1, fpn::fixed8_40>;
    using f8_48vec1 = vec<1, fpn::fixed8_48>;
    using f8_56vec1 = vec<1, fpn::fixed8_56>;

    using f16_8vec1  = vec<1, fpn::fixed16_8>;
    using f16_16vec1 = vec<1, fpn::fixed16_16>;
    using f16_24vec1 = vec<1, fpn::fixed16_24>;
    using f16_32vec1 = vec<1, fpn::fixed16_32>;
    using f16_40vec1 = vec<1, fpn::fixed16_40>;
    using f16_48vec1 = vec<1, fpn::fixed16_48>;

    using f24_8vec1  = vec<1, fpn::fixed24_8>;
    using f24_16vec1 = vec<1, fpn::fixed24_16>;
    using f24_24vec1 = vec<1, fpn::fixed24_24>;
    using f24_32vec1 = vec<1, fpn::fixed24_32>;
    using f24_40vec1 = vec<1, fpn::fixed24_40>;

    using f32_8vec1  = vec<1, fpn::fixed32_8>;
    using f32_16vec1 = vec<1, fpn::fixed32_16>;
    using f32_24vec1 = vec<1, fpn::fixed32_24>;
    using f32_32vec1 = vec<1, fpn::fixed32_32>;

    using f40_8vec1  = vec<1, fpn::fixed40_8>;
    using f40_16vec1 = vec<1, fpn::fixed40_16>;
    using f40_24vec1 = vec<1, fpn::fixed40_24>;

    using f48_8vec1  = vec<1, fpn::fixed48_8>;
    using f48_16vec1 = vec<1, fpn::fixed48_16>;

    using f56_8vec1  = vec<1, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8vec2  = vec<2, fpn::fixed8_8>;
    using f8_16vec2 = vec<2, fpn::fixed8_16>;
    using f8_24vec2 = vec<2, fpn::fixed8_24>;
    using f8_32vec2 = vec<2, fpn::fixed8_32>;
    using f8_40vec2 = vec<2, fpn::fixed8_40>;
    using f8_48vec2 = vec<2, fpn::fixed8_48>;
    using f8_56vec2 = vec<2, fpn::fixed8_56>;

    using f16_8vec2  = vec<2, fpn::fixed16_8>;
    using f16_16vec2 = vec<2, fpn::fixed16_16>;
    using f16_24vec2 = vec<2, fpn::fixed16_24>;
    using f16_32vec2 = vec<2, fpn::fixed16_32>;
    using f16_40vec2 = vec<2, fpn::fixed16_40>;
    using f16_48vec2 = vec<2, fpn::fixed16_48>;

    using f24_8vec2  = vec<2, fpn::fixed24_8>;
    using f24_16vec2 = vec<2, fpn::fixed24_16>;
    using f24_24vec2 = vec<2, fpn::fixed24_24>;
    using f24_32vec2 = vec<2, fpn::fixed24_32>;
    using f24_40vec2 = vec<2, fpn::fixed24_40>;

    using f32_8vec2  = vec<2, fpn::fixed32_8>;
    using f32_16vec2 = vec<2, fpn::fixed32_16>;
    using f32_24vec2 = vec<2, fpn::fixed32_24>;
    using f32_32vec2 = vec<2, fpn::fixed32_32>;

    using f40_8vec2  = vec<2, fpn::fixed40_8>;
    using f40_16vec2 = vec<2, fpn::fixed40_16>;
    using f40_24vec2 = vec<2, fpn::fixed40_24>;

    using f48_8vec2  = vec<2, fpn::fixed48_8>;
    using f48_16vec2 = vec<2, fpn::fixed48_16>;

    using f56_8vec2  = vec<2, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8vec3  = vec<3, fpn::fixed8_8>;
    using f8_16vec3 = vec<3, fpn::fixed8_16>;
    using f8_24vec3 = vec<3, fpn::fixed8_24>;
    using f8_32vec3 = vec<3, fpn::fixed8_32>;
    using f8_40vec3 = vec<3, fpn::fixed8_40>;
    using f8_48vec3 = vec<3, fpn::fixed8_48>;
    using f8_56vec3 = vec<3, fpn::fixed8_56>;

    using f16_8vec3  = vec<3, fpn::fixed16_8>;
    using f16_16vec3 = vec<3, fpn::fixed16_16>;
    using f16_24vec3 = vec<3, fpn::fixed16_24>;
    using f16_32vec3 = vec<3, fpn::fixed16_32>;
    using f16_40vec3 = vec<3, fpn::fixed16_40>;
    using f16_48vec3 = vec<3, fpn::fixed16_48>;

    using f24_8vec3  = vec<3, fpn::fixed24_8>;
    using f24_16vec3 = vec<3, fpn::fixed24_16>;
    using f24_24vec3 = vec<3, fpn::fixed24_24>;
    using f24_32vec3 = vec<3, fpn::fixed24_32>;
    using f24_40vec3 = vec<3, fpn::fixed24_40>;

    using f32_8vec3  = vec<3, fpn::fixed32_8>;
    using f32_16vec3 = vec<3, fpn::fixed32_16>;
    using f32_24vec3 = vec<3, fpn::fixed32_24>;
    using f32_32vec3 = vec<3, fpn::fixed32_32>;

    using f40_8vec3  = vec<3, fpn::fixed40_8>;
    using f40_16vec3 = vec<3, fpn::fixed40_16>;
    using f40_24vec3 = vec<3, fpn::fixed40_24>;

    using f48_8vec3  = vec<3, fpn::fixed48_8>;
    using f48_16vec3 = vec<3, fpn::fixed48_16>;

    using f56_8vec3  = vec<3, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8vec4  = vec<4, fpn::fixed8_8>;
    using f8_16vec4 = vec<4, fpn::fixed8_16>;
    using f8_24vec4 = vec<4, fpn::fixed8_24>;
    using f8_32vec4 = vec<4, fpn::fixed8_32>;
    using f8_40vec4 = vec<4, fpn::fixed8_40>;
    using f8_48vec4 = vec<4, fpn::fixed8_48>;
    using f8_56vec4 = vec<4, fpn::fixed8_56>;

    using f16_8vec4  = vec<4, fpn::fixed16_8>;
    using f16_16vec4 = vec<4, fpn::fixed16_16>;
    using f16_24vec4 = vec<4, fpn::fixed16_24>;
    using f16_32vec4 = vec<4, fpn::fixed16_32>;
    using f16_40vec4 = vec<4, fpn::fixed16_40>;
    using f16_48vec4 = vec<4, fpn::fixed16_48>;

    using f24_8vec4  = vec<4, fpn::fixed24_8>;
    using f24_16vec4 = vec<4, fpn::fixed24_16>;
    using f24_24vec4 = vec<4, fpn::fixed24_24>;
    using f24_32vec4 = vec<4, fpn::fixed24_32>;
    using f24_40vec4 = vec<4, fpn::fixed24_40>;

    using f32_8vec4  = vec<4, fpn::fixed32_8>;
    using f32_16vec4 = vec<4, fpn::fixed32_16>;
    using f32_24vec4 = vec<4, fpn::fixed32_24>;
    using f32_32vec4 = vec<4, fpn::fixed32_32>;

    using f40_8vec4  = vec<4, fpn::fixed40_8>;
    using f40_16vec4 = vec<4, fpn::fixed40_16>;
    using f40_24vec4 = vec<4, fpn::fixed40_24>;

    using f48_8vec4  = vec<4, fpn::fixed48_8>;
    using f48_16vec4 = vec<4, fpn::fixed48_16>;

    using f56_8vec4  = vec<4, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8mat2  = mat<2, 2, fpn::fixed8_8>;
    using f8_16mat2 = mat<2, 2, fpn::fixed8_16>;
    using f8_24mat2 = mat<2, 2, fpn::fixed8_24>;
    using f8_32mat2 = mat<2, 2, fpn::fixed8_32>;
    using f8_40mat2 = mat<2, 2, fpn::fixed8_40>;
    using f8_48mat2 = mat<2, 2, fpn::fixed8_48>;
    using f8_56mat2 = mat<2, 2, fpn::fixed8_56>;

    using f16_8mat2  = mat<2, 2, fpn::fixed16_8>;
    using f16_16mat2 = mat<2, 2, fpn::fixed16_16>;
    using f16_24mat2 = mat<2, 2, fpn::fixed16_24>;
    using f16_32mat2 = mat<2, 2, fpn::fixed16_32>;
    using f16_40mat2 = mat<2, 2, fpn::fixed16_40>;
    using f16_48mat2 = mat<2, 2, fpn::fixed16_48>;

    using f24_8mat2  = mat<2, 2, fpn::fixed24_8>;
    using f24_16mat2 = mat<2, 2, fpn::fixed24_16>;
    using f24_24mat2 = mat<2, 2, fpn::fixed24_24>;
    using f24_32mat2 = mat<2, 2, fpn::fixed24_32>;
    using f24_40mat2 = mat<2, 2, fpn::fixed24_40>;

    using f32_8mat2  = mat<2, 2, fpn::fixed32_8>;
    using f32_16mat2 = mat<2, 2, fpn::fixed32_16>;
    using f32_24mat2 = mat<2, 2, fpn::fixed32_24>;
    using f32_32mat2 = mat<2, 2, fpn::fixed32_32>;

    using f40_8mat2  = mat<2, 2, fpn::fixed40_8>;
    using f40_16mat2 = mat<2, 2, fpn::fixed40_16>;
    using f40_24mat2 = mat<2, 2, fpn::fixed40_24>;

    using f48_8mat2  = mat<2, 2, fpn::fixed48_8>;
    using f48_16mat2 = mat<2, 2, fpn::fixed48_16>;

    using f56_8mat2  = mat<2, 2, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8mat3  = mat<3, 3, fpn::fixed8_8>;
    using f8_16mat3 = mat<3, 3, fpn::fixed8_16>;
    using f8_24mat3 = mat<3, 3, fpn::fixed8_24>;
    using f8_32mat3 = mat<3, 3, fpn::fixed8_32>;
    using f8_40mat3 = mat<3, 3, fpn::fixed8_40>;
    using f8_48mat3 = mat<3, 3, fpn::fixed8_48>;
    using f8_56mat3 = mat<3, 3, fpn::fixed8_56>;

    using f16_8mat3  = mat<3, 3, fpn::fixed16_8>;
    using f16_16mat3 = mat<3, 3, fpn::fixed16_16>;
    using f16_24mat3 = mat<3, 3, fpn::fixed16_24>;
    using f16_32mat3 = mat<3, 3, fpn::fixed16_32>;
    using f16_40mat3 = mat<3, 3, fpn::fixed16_40>;
    using f16_48mat3 = mat<3, 3, fpn::fixed16_48>;

    using f24_8mat3  = mat<3, 3, fpn::fixed24_8>;
    using f24_16mat3 = mat<3, 3, fpn::fixed24_16>;
    using f24_24mat3 = mat<3, 3, fpn::fixed24_24>;
    using f24_32mat3 = mat<3, 3, fpn::fixed24_32>;
    using f24_40mat3 = mat<3, 3, fpn::fixed24_40>;

    using f32_8mat3  = mat<3, 3, fpn::fixed32_8>;
    using f32_16mat3 = mat<3, 3, fpn::fixed32_16>;
    using f32_24mat3 = mat<3, 3, fpn::fixed32_24>;
    using f32_32mat3 = mat<3, 3, fpn::fixed32_32>;

    using f40_8mat3  = mat<3, 3, fpn::fixed40_8>;
    using f40_16mat3 = mat<3, 3, fpn::fixed40_16>;
    using f40_24mat3 = mat<3, 3, fpn::fixed40_24>;

    using f48_8mat3  = mat<3, 3, fpn::fixed48_8>;
    using f48_16mat3 = mat<3, 3, fpn::fixed48_16>;

    using f56_8mat3  = mat<3, 3, fpn::fixed56_8>;
}
namespace glm
{
    using f8_8mat4  = mat<4, 4, fpn::fixed8_8>;
    using f8_16mat4 = mat<4, 4, fpn::fixed8_16>;
    using f8_24mat4 = mat<4, 4, fpn::fixed8_24>;
    using f8_32mat4 = mat<4, 4, fpn::fixed8_32>;
    using f8_40mat4 = mat<4, 4, fpn::fixed8_40>;
    using f8_48mat4 = mat<4, 4, fpn::fixed8_48>;
    using f8_56mat4 = mat<4, 4, fpn::fixed8_56>;

    using f16_8mat4  = mat<4, 4, fpn::fixed16_8>;
    using f16_16mat4 = mat<4, 4, fpn::fixed16_16>;
    using f16_24mat4 = mat<4, 4, fpn::fixed16_24>;
    using f16_32mat4 = mat<4, 4, fpn::fixed16_32>;
    using f16_40mat4 = mat<4, 4, fpn::fixed16_40>;
    using f16_48mat4 = mat<4, 4, fpn::fixed16_48>;

    using f24_8mat4  = mat<4, 4, fpn::fixed24_8>;
    using f24_16mat4 = mat<4, 4, fpn::fixed24_16>;
    using f24_24mat4 = mat<4, 4, fpn::fixed24_24>;
    using f24_32mat4 = mat<4, 4, fpn::fixed24_32>;
    using f24_40mat4 = mat<4, 4, fpn::fixed24_40>;

    using f32_8mat4  = mat<4, 4, fpn::fixed32_8>;
    using f32_16mat4 = mat<4, 4, fpn::fixed32_16>;
    using f32_24mat4 = mat<4, 4, fpn::fixed32_24>;
    using f32_32mat4 = mat<4, 4, fpn::fixed32_32>;

    using f40_8mat4  = mat<4, 4, fpn::fixed40_8>;
    using f40_16mat4 = mat<4, 4, fpn::fixed40_16>;
    using f40_24mat4 = mat<4, 4, fpn::fixed40_24>;

    using f48_8mat4  = mat<4, 4, fpn::fixed48_8>;
    using f48_16mat4 = mat<4, 4, fpn::fixed48_16>;

    using f56_8mat4  = mat<4, 4, fpn::fixed56_8>;
}
#else
namespace glm
{
    using f8_8vec1  = vec<1, fpn::fixed8_8>;
    using f8_16vec1 = vec<1, fpn::fixed8_16>;
    using f8_24vec1 = vec<1, fpn::fixed8_24>;

    using f16_8vec1  = vec<1, fpn::fixed16_8>;
    using f16_16vec1 = vec<1, fpn::fixed16_16>;

    using f24_8vec1  = vec<1, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8vec2  = vec<2, fpn::fixed8_8>;
    using f8_16vec2 = vec<2, fpn::fixed8_16>;
    using f8_24vec2 = vec<2, fpn::fixed8_24>;

    using f16_8vec2  = vec<2, fpn::fixed16_8>;
    using f16_16vec2 = vec<2, fpn::fixed16_16>;

    using f24_8vec2  = vec<2, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8vec3  = vec<3, fpn::fixed8_8>;
    using f8_16vec3 = vec<3, fpn::fixed8_16>;
    using f8_24vec3 = vec<3, fpn::fixed8_24>;

    using f16_8vec3  = vec<3, fpn::fixed16_8>;
    using f16_16vec3 = vec<3, fpn::fixed16_16>;

    using f24_8vec3  = vec<3, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8vec4  = vec<4, fpn::fixed8_8>;
    using f8_16vec4 = vec<4, fpn::fixed8_16>;
    using f8_24vec4 = vec<4, fpn::fixed8_24>;

    using f16_8vec4  = vec<4, fpn::fixed16_8>;
    using f16_16vec4 = vec<4, fpn::fixed16_16>;

    using f24_8vec4  = vec<4, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8mat2  = mat<2, 2, fpn::fixed8_8>;
    using f8_16mat2 = mat<2, 2, fpn::fixed8_16>;
    using f8_24mat2 = mat<2, 2, fpn::fixed8_24>;

    using f16_8mat2  = mat<2, 2, fpn::fixed16_8>;
    using f16_16mat2 = mat<2, 2, fpn::fixed16_16>;

    using f24_8mat2  = mat<2, 2, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8mat3  = mat<3, 3, fpn::fixed8_8>;
    using f8_16mat3 = mat<3, 3, fpn::fixed8_16>;
    using f8_24mat3 = mat<3, 3, fpn::fixed8_24>;

    using f16_8mat3  = mat<3, 3, fpn::fixed16_8>;
    using f16_16mat3 = mat<3, 3, fpn::fixed16_16>;

    using f24_8mat3  = mat<3, 3, fpn::fixed24_8>;
}
namespace glm
{
    using f8_8mat4  = mat<4, 4, fpn::fixed8_8>;
    using f8_16mat4 = mat<4, 4, fpn::fixed8_16>;
    using f8_24mat4 = mat<4, 4, fpn::fixed8_24>;

    using f16_8mat4  = mat<4, 4, fpn::fixed16_8>;
    using f16_16mat4 = mat<4, 4, fpn::fixed16_16>;

    using f24_8mat4  = mat<4, 4, fpn::fixed24_8>;
}
#endif
