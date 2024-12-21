#ifndef HITTABLE_H
#define HITTABLE_H
#include "aabb.h"
class material;

class hit_record
{
public:
    point3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    double u;
    double v;
    bool front_face;

    void set_face_normal(const ray &r, const vec3 &outward_normal)
    {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;

    virtual aabb bounding_box() const = 0;
};
class translate : hittable
{
public:
    translate(shared_ptr<hittable> object, const vec3 &offset) : object(object), offset(offset) { bbox = object->bounding_box() + offset; }
    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        // Create ray with origin translated by offset
        ray moved_r(r.origin() - offset, r.direction(), r.time());
        // Check if the new ray hits the object
        if (!object->hit(moved_r, ray_t, rec))
            return false;
        // Correct the hit position by the offset
        rec.p += offset;

        return true;
    }
    aabb bounding_box() const override { return bbox; }

private:
    shared_ptr<hittable> object;
    vec3 offset;
    aabb bbox;
};

#endif