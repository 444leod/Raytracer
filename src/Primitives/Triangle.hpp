#pragma once

#include "APrimitive.hpp"
#include "HitResult.hpp"
#include <optional>

namespace rtx {
    class Triangle : public APrimitive {
    public:
        Triangle();
        Triangle(Color color, Vector3d p1, Vector3d p2, Vector3d p3);
        ~Triangle() = default;

        virtual std::optional<HitResult> hits(const Ray& ray) const override;
        void setP1(const Vector3d& p1) { this->_p1 = p1; }
        void setP2(const Vector3d& p2) { this->_p2 = p2; }
        void setP3(const Vector3d& p3) { this->_p3 = p3; }

    private:
        Vector3d _p1;
        Vector3d _p2;
        Vector3d _p3;
    };
}
