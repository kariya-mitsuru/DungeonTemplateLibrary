﻿/*#######################################################################################
	Made by Kasugaccho
	Made by As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	This code is licensed under CC0.
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DUNGEON_MATRIX_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_DUNGEON_MATRIX_HPP

#include <DTL/Macros/constexpr.hpp>
#include <DTL/Type/SizeT.hpp>

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する
		namespace stl {

			//サイズ変更( ::std::vector, ::std::deque等)
			template<typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void resize(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_) noexcept {
				matrix_.resize(y_);
				for (::dtl::type::size row{}; row < y_; ++row)
					matrix_[row].resize(x_);
			}
			template<typename Matrix_Int_, typename Matrix_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void resize(Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const Matrix_Int_ value_) noexcept {
				matrix_.resize(y_);
				for (::dtl::type::size row{}; row < y_; ++row) {
					matrix_[row].resize(x_);
					for (::dtl::type::size col{}; col < x_; ++col)
						matrix_[row][col] = value_;
				}
			}

		}
	}
}
namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する
		namespace layer {
			namespace stl {

				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void resize(Matrix_& matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size layer_) noexcept {
					matrix_.resize(y_);
					for (::dtl::type::size row{}; row < y_; ++row) {
						matrix_[row].resize(x_);
						for (::dtl::type::size col{}; col < x_; ++col)
							matrix_[row][col].resize(layer_);
					}
				}
				template<typename Matrix_Int_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void resize(Matrix_ & matrix_, const ::dtl::type::size x_, const ::dtl::type::size y_, const ::dtl::type::size layer_, const Matrix_Int_ value_) noexcept {
					matrix_.resize(y_);
					for (::dtl::type::size row{}; row < y_; ++row) {
						matrix_[row].resize(x_);
						for (::dtl::type::size col{}; col < x_; ++col) {
							matrix_[row][col].resize(layer_);
							for (::dtl::type::size layer{}; layer < layer_; ++layer)
								matrix_[row][col][layer_] = value_;
						}
					}
				}
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void resize(Matrix_ & matrix_, const ::dtl::type::size layer_) noexcept {
					for (::dtl::type::size row{}; row < matrix_.size(); ++row)
						for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
							matrix_[row][col].resize(layer_);
				}
				template<typename Matrix_Int_, typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void resize(Matrix_ & matrix_, const ::dtl::type::size layer_, const Matrix_Int_ value_) noexcept {
					for (::dtl::type::size row{}; row < matrix_.size(); ++row)
						for (::dtl::type::size col{}; col < matrix_[row].size(); ++col) {
							matrix_[row][col].resize(layer_);
							for (::dtl::type::size layer{}; layer < layer_; ++layer)
								matrix_[row][col][layer_] = value_;
						}
				}

			}
		}
	}
}

namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する
		namespace stl {
			namespace tool {

				//上下反転
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void flip(Matrix_& matrix_) noexcept {
					for (::dtl::type::size row{}, row2{ matrix_.size() - 1 };; ++row, --row2) {
						if (row >= row2) break;
						for (::dtl::type::size col{}; col < matrix_[row].size(); ++col) {
							const auto&& tmp{ (matrix_[row][col] + 0) };
							matrix_[row][col] = matrix_[row2][col];
							matrix_[row2][col] = ::std::move(tmp);
						}
					}
				}
				//左右反転
				template<typename Matrix_>
				DTL_VERSIONING_CPP14_CONSTEXPR
					void mirror(Matrix_& matrix_) noexcept {
					for (::dtl::type::size row{}; row < matrix_.size(); ++row)
						for (::dtl::type::size col{}, col2{ matrix_[row].size() - 1 };; ++col, --col2) {
							if (col >= col2) break;
							const auto && tmp{ (matrix_[row][col] + 0) };
							matrix_[row][col] = matrix_[row][col2];
							matrix_[row][col2] = ::std::move(tmp);
						}
				}

			}
		}
	}
}

namespace dtl {
	inline namespace utility { //"dtl::utility"名前空間に属する
		namespace tool {

			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void convertSTL_intoDefault(Matrix_& matrix_, ::dtl::type::size& x_, ::dtl::type::size& y_, const Matrix2_& matrix2_) noexcept {
				for (::dtl::type::size row{}; row < matrix_.size(); ++row)
					for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
						matrix_[row][col] = matrix2_[row][col];
				((y_ = matrix2_.size()) == 0) ? (x_ = 0) : (x_ = matrix2_[0].size());
			}
			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void convertSTL_intoArray(Matrix_ & matrix_, ::dtl::type::size & x_, ::dtl::type::size & y_, const Matrix2_ & matrix2_) noexcept {
				for (::dtl::type::size row{}; row < matrix_.size(); ++row)
					for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
						matrix_[row * x_ + col] = matrix2_[row][col];
				((y_ = matrix2_.size()) == 0) ? (x_ = 0) : (x_ = matrix2_[0].size());
			}
			template<typename Matrix_, typename Matrix2_>
			DTL_VERSIONING_CPP14_CONSTEXPR
				void convertSTL_intoLayer(Matrix_ & matrix_, ::dtl::type::size & layer_, const Matrix2_ & matrix2_) noexcept {
				for (::dtl::type::size row{}; row < matrix_.size(); ++row)
					for (::dtl::type::size col{}; col < matrix_[row].size(); ++col)
						matrix_[row][col][layer_] = matrix2_[row][col];
			}

		}
	}
}

#endif //Included Dungeon Template Library