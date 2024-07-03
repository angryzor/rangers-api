#pragma once

#ifdef EXPORTING_TYPES

namespace csl::math {
	class Vector2 {
	public:
		float x; float y;
	};

	class alignas(16) Vector3 {
	public:
		float x; float y; float z;
	};

	class alignas(16) Vector4 {
	public:
		float x; float y; float z; float w;
	};

	class alignas(16) Quaternion  {
	public:
		float x; float y; float z; float w;
		void SetRotationBetweenVectors(const Vector4& a, const Vector4& b, const Vector4& fallback);
		static Vector4 RotateVector(const Quaternion& quaternion, const Vector4& vector);
	};

	class alignas(16) Matrix44 {
	public:
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
		static Matrix44 CreateViewMatrix(Vector3 position, Vector3 up, Vector3 target);
		static Matrix44 CreateOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
		static Matrix44 CreatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
	};

	class alignas(16) Matrix34 {
	public:
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	};

	class Position {
	public:
		float x; float y; float z;
	};
}

#else

#ifndef NO_EIGEN_MATH
#include "Eigen/Eigen"
namespace csl::math {
	typedef Eigen::Matrix<float, 2, 1, Eigen::DontAlign> Vector2;
	typedef Eigen::Vector3f Vector3;
	typedef Eigen::Vector4f Vector4;
	typedef Eigen::Quaternionf Quaternion;
	typedef Eigen::Affine3f Matrix34;
	typedef Eigen::Matrix4f Matrix44;
	typedef Eigen::Matrix<float, 3, 1, Eigen::DontAlign> Position;

	inline bool operator==(const Quaternion& one, const Quaternion& other) {
		return one.isApprox(other);
	}

	inline bool operator!=(const Quaternion& one, const Quaternion& other) {
		return !(one == other);
	}
}
#endif

#endif

namespace csl::math 
{
	class Transform
	{
	public:
		Vector3 position{ 0.0f, 0.0f, 0.0f };
		Quaternion rotation{ 0.0f, 0.0f, 0.0f, 1.0f };
		Vector3 scale{ 0.0f, 0.0f, 0.0f };

		inline bool operator==(const Transform& other) const {
			return position == other.position && rotation == other.rotation && scale == other.scale;
		}

		inline bool operator!=(const Transform& other) const {
			return !operator==(other);
		}
	};

	class CalculatedTransform
	{
	public:
		Matrix34 m_Mtx;
		Vector3 m_Scale;
		size_t m_Flags;
	};
}

namespace csl::geom {
	class Aabb
	{
	public:
		math::Vector3 m_Min{};
		math::Vector3 m_Max{};

		static Aabb Transform(const math::Matrix34& matrix, const Aabb& aabb);
		math::Vector3 Center() const;
		bool Intersect(const Aabb& aabb) const;

		inline void AddPoint(const csl::math::Vector3& point) {
			m_Min = m_Min.cwiseMin(point);
			m_Max = m_Max.cwiseMax(point);
		}
	};
}

namespace csl::math
{
	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);
	bool Intersection(const Vector3& point, geom::Aabb aabb);
}
