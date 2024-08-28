#ifndef SUPERKK_TRANSFORM_H
#define SUPERKK_TRANSFORM_H


#include "Mat3.h"

class Transform {
private:
    Vec2 anchor;
    Vec2 translation;
    Vec2 scale;
    double angle;
    Mat3 mat;

public:
    Transform() : mat(), translation(0, 0), scale(1, 1), angle(0) {}
    Transform(const Vec2& translation, const Vec2& scale, double angle) :
    translation(translation), scale(scale), angle(angle), mat() {}

    void rotate_by(double new_angle) {
        mat.translate(-anchor.get_x(), -anchor.get_y());
        this->angle += new_angle;
        mat.rotate(angle);
        mat.translate(anchor.get_x(), anchor.get_y());
    }

    void scale_by(double sx, double sy) {
        mat.translate(-anchor.get_x(), -anchor.get_y());
        scale = Vec2::multiply(scale, Vec2(sx, sy));
        mat.scale(scale.get_x(), scale.get_y());
        mat.translate(anchor.get_x(), anchor.get_y());
    }

    void translate_by(double tx, double ty) {
        mat.translate(-anchor.get_x(), -anchor.get_y());
        translation += Vec2(tx, ty);
        mat.translate(translation.get_x(), translation.get_y());
        mat.translate(anchor.get_x(), anchor.get_y());
    }

    void apply(const Transform& transform) {
        rotate_by(transform.angle);
        scale_by(transform.scale.get_x(), transform.scale.get_y());
        translate_by(transform.translation.get_x(), transform.translation.get_y());
    }

    void reset() {
        mat.set_identity();
        translation = Vec2(0, 0);
        scale = Vec2(1, 1);
        angle = 0;
        anchor = Vec2(0, 0);
    }

    Vec2 apply_to(const Vec2& vec) const {
        double w = mat.get(2, 0) * vec.get_x() + mat.get(2, 1) * vec.get_y() + mat.get(2, 2);
        return {
            (mat.get(0, 0) * vec.get_x() + mat.get(0, 1) * vec.get_y() + mat.get(0, 2)) / w,
            (mat.get(1, 0) * vec.get_x() + mat.get(1, 1) * vec.get_y() + mat.get(1, 2)) / w
        };
    }


    const Vec2 &get_translation() const {
        return translation;
    }

    const Vec2 &get_scale() const {
        return scale;
    }

    double getAngle() const {
        return angle;
    }

    const Vec2 &getAnchor() const {
        return anchor;
    }

    void setAnchor(const Vec2 &anchor) {
        this->anchor = anchor;
    }

    void setTranslation(const Vec2 &translation) {
//        TODO
        this->translation = translation;
    }

    void set_scale(const Vec2 &scale) {
        scale_by(scale.get_x() / this->scale.get_x(), scale.get_y() / this->scale.get_y());
        this->scale = scale;
    }

    void setAngle(double angle) {
        rotate_by(angle-this->angle);
        this->angle = angle;
    }

    void set_position(const Vec2 &position) {
        translate_by(position.get_x() - translation.get_x(), position.get_y() - translation.get_y());
        translation = position - anchor;
    }
};


#endif //SUPERKK_TRANSFORM_H
