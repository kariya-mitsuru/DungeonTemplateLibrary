﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_COPY_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_UTILITY_COPY_HPP

/* Character Code : UTF-8 (BOM) */
/* Bug Check : not checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

namespace dtl {
	inline namespace utility {

		namespace tool {

			//キャストしてコピー
			template<typename Matrix_Int_, typename Value_Int_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void castCopyValue(Matrix_Int_& value_, const Value_Int_& value2_) noexcept {
				value_ = static_cast<Matrix_Int_>(value2_);
			}

			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void copyMatrix(Matrix_& matrix_, const Matrix_& matrix2_) noexcept {
				matrix_ = matrix2_;
			}

		} //namespace

		namespace stl {

			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_) noexcept {
				for (dtl::type::size row{}; row < matrix_.size(); ++row)
					for (dtl::type::size col{}; col < matrix_[row].size(); ++col)
						matrix_[row][col] = matrix2_[row][col];
			}

		} //namespace

		namespace normal {

			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const dtl::type::size x_, const dtl::type::size y_) noexcept {
				for (dtl::type::size row{}; row < y_; ++row)
					for (dtl::type::size col{}; col < x_; ++col)
						matrix_[row][col] = matrix2_[row][col];
			}

		} //namespace

		namespace array {

			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const dtl::type::size x_, const dtl::type::size y_) noexcept {
				for (dtl::type::size row{}; row < y_; ++row)
					for (dtl::type::size col{}; col < x_; ++col)
						matrix_[row * x_ + col] = matrix2_[row * x_ + col];
			}

		} //namespace

		namespace layer {
			namespace stl {

				template<typename Matrix_, typename Matrix2_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const dtl::type::size layer_) noexcept {
					for (dtl::type::size row{}; row < matrix_.size(); ++row)
						for (dtl::type::size col{}; col < matrix_[row].size(); ++col)
							matrix_[row][col][layer_] = matrix2_[row][col][layer_];
				}

			} //namespace
		}

		namespace layer {
			namespace normal {

				template<typename Matrix_, typename Matrix2_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void copyMatrix(Matrix_& matrix_, const Matrix2_& matrix2_, const dtl::type::size layer_, const dtl::type::size x_, const dtl::type::size y_) noexcept {
					for (dtl::type::size row{}; row < y_; ++row)
						for (dtl::type::size col{}; col < x_; ++col)
							matrix_[row][col][layer_] = matrix2_[row][col][layer_];
				}

			} //namespace

		}
	}
}

#endif //Included Dungeon Template Library