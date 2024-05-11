#pragma once

#include "APrimitive.hpp"

namespace rtx {
    class Triangle : public APrimitive {
    public:
        Triangle() = delete;
        Triangle(Color color, Vector3d p1, Vector3d p2, Vector3d p3);
        ~Triangle() = default;

        virtual std::optional<HitResult> hits(const Ray& ray) const override;

    private:
        Vector3d _p1;
        Vector3d _p2;
        Vector3d _p3;
    };
}
