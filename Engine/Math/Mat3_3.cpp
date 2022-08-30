#include "Mat3_3.h"

namespace Solas {
	const Matrix3x3 Matrix3x3::zero{
		Vector3{0, 0, 0,},
		Vector3{0, 0, 0,},
		Vector3{0, 0, 0,}
	};

	const Matrix3x3 Matrix3x3::identity{
		Vector3{1, 0, 0,},
		Vector3{0, 1, 0,},
		Vector3{0, 0, 1,}
	};
}