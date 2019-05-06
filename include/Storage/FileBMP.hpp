﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_BMP_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_STORAGE_FILE_BMP_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileBMP-(ストレージクラス)/
#######################################################################################*/

/* Character Code : UTF-8 (BOM) */
/* Bug Check : already checked */
/* Android NDK Compile (Clang 5.0) : already checked */

#include <cstddef>
#include <cstdint>
#include <utility>
#include <string>
#include <fstream>
#include <Base/Struct.hpp>
#include <Utility/IsOutputCast.hpp>
#include <Macros/nodiscard.hpp>
#include <Macros/constexpr.hpp>

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <ThirdParty/STB/stb_image_write.h>
#endif

namespace dtl {
	inline namespace storage {

		//マスを指定した数値で埋める
		template<typename Matrix_Int_>
		class FileBMP {
		private:


			///// エイリアス /////

			using Index_Size = std::size_t;



			///// メンバ変数 /////

			Index_Size start_x{};
			Index_Size start_y{};
			Index_Size width{};
			Index_Size height{};
			std::string str{};
			std::size_t color_num{ 3 };


			///// 代入処理 /////

			template<typename Matrix_, typename Function_>
			DTL_CPP14_CONSTEXPR
				inline void substitutionSTL(const std::size_t point_max_x_, std::unique_ptr<unsigned char[]>& data_, const Matrix_& matrix_, const Index_Size end_x_, const Index_Size end_y_, Function_&& function_) const noexcept {
				function_(matrix_[end_y_][end_x_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}
			template<typename Matrix_, typename Function_>
			DTL_CPP14_CONSTEXPR
				inline void substitutionArray(const std::size_t point_max_x_, std::unique_ptr<unsigned char[]> & data_, const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Function_ && function_) const noexcept {
				function_(matrix_[end_y_][end_x_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}
			template<typename Matrix_, typename Function_>
			DTL_CPP14_CONSTEXPR
				inline void substitutionLayer(const std::size_t point_max_x_, std::unique_ptr<unsigned char[]> & data_, const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Function_ && function_) const noexcept {
				function_(matrix_[end_y_][end_x_], &data_[((end_y_ - this->start_y) * (point_max_x_ - this->start_x) + (end_x_ - this->start_x)) * this->color_num]);
			}

			///// 基本処理 /////

			//Normal
			template<typename Matrix_, typename ...Args_>
				bool writeNormal(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				std::unique_ptr<unsigned char[]> data(new(std::nothrow) unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionSTL(end_x_, data, matrix_, col, row, args_...);
				stbi_write_bmp(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get());
				return true;
			}

			//LayerNormal
			template<typename Matrix_, typename ...Args_>
				bool writeLayerNormal(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size end_x_, const Index_Size end_y_, Args_ && ... args_) const noexcept {
				std::unique_ptr<unsigned char[]> data(new(std::nothrow) unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionLayer(end_x_, data, matrix_, layer_, col, row, args_...);
				stbi_write_bmp(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get());
				return true;
			}

			//Array
			template<typename Matrix_, typename ...Args_>
				bool writeArray(const Matrix_ & matrix_, const Index_Size end_x_, const Index_Size end_y_, const Index_Size max_x_, Args_ && ... args_) const noexcept {
				std::unique_ptr<unsigned char[]> data(new(std::nothrow) unsigned char[(end_x_ - this->start_x) * (end_y_ - this->start_y) * this->color_num]);
				if (!data) return false;
				for (Index_Size row{ this->start_y }; row < end_y_; ++row)
					for (Index_Size col{ this->start_x }; col < end_x_; ++col)
						this->substitutionArray(end_x_, data, matrix_, col, row, max_x_, args_...);
				stbi_write_bmp(this->str.c_str(), static_cast<int>(end_x_ - this->start_x), static_cast<int>(end_y_ - this->start_y), static_cast<int>(this->color_num), data.get());
				return true;
			}

		public:


			///// 情報取得 /////

			DTL_NODISCARD
				constexpr Index_Size getPointX() const noexcept {
				return this->start_x;
			}
			DTL_NODISCARD
				constexpr Index_Size getPointY() const noexcept {
				return this->start_y;
			}
			DTL_NODISCARD
				constexpr Index_Size getWidth() const noexcept {
				return this->width;
			}
			DTL_NODISCARD
				constexpr Index_Size getHeight() const noexcept {
				return this->height;
			}
			DTL_NODISCARD
				std::string getString() const noexcept {
				return this->str;
			}


			///// 生成呼び出し /////

			//STL
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, Function_ && function_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//LayerSTL
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_, Function_ && function_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= ((matrix_.size() == 0) ? 0 : matrix_[0].size())) ? ((matrix_.size() == 0) ? 0 : matrix_[0].size()) : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= matrix_.size()) ? matrix_.size() : this->start_y + this->height, function_);
			}

			//Normal
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeNormal(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//LayerNormal
			template<typename Matrix_, typename Function_>
			constexpr bool write(const Matrix_ & matrix_, const Index_Size layer_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeLayerNormal(matrix_, layer_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, function_);
			}

			//Array
			template<typename Matrix_, typename Function_>
			constexpr bool writeArray(const Matrix_ & matrix_, const Index_Size max_x_, const Index_Size max_y_, Function_ && function_) const noexcept {
				return this->writeArray(matrix_, (this->width == 0 || this->start_x + this->width >= max_x_) ? max_x_ : this->start_x + this->width, (this->height == 0 || this->start_y + this->height >= max_y_) ? max_y_ : this->start_y + this->height, max_x_, function_);
			}


			///// 生成呼び出しファンクタ /////

			template<typename Matrix_, typename ...Args_>
			constexpr bool operator()(const Matrix_ & matrix_, Args_ && ... args_) const noexcept {
				return this->write(matrix_, std::forward<Args_>(args_)...);
			}


			///// ダンジョン行列生成 /////

			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& create(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->write(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}
			template<typename Matrix_, typename ...Args_>
			DTL_CPP14_CONSTEXPR
				Matrix_&& createArray(Matrix_ && matrix_, Args_ && ... args_) const noexcept {
				this->writeArray(matrix_, std::forward<Args_>(args_)...);
				return std::forward<Matrix_>(matrix_);
			}


			///// 消去 /////

			//始点座標Xを初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearPointX() noexcept {
				this->start_x = 0;
				return *this;
			}
			//始点座標Yを初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearPointY() noexcept {
				this->start_y = 0;
				return *this;
			}
			//範囲の大きさ(X軸方向)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearWidth() noexcept {
				this->width = 0;
				return *this;
			}
			//範囲の大きさ(Y軸方向)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearHeight() noexcept {
				this->height = 0;
				return *this;
			}
			//始点座標(X,Y)を初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearPoint() noexcept {
				this->clearPointX();
				this->clearPointY();
				return *this;
			}
			//描画範囲を初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clearRange() noexcept {
				this->clearPointX();
				this->clearPointY();
				this->clearWidth();
				this->clearHeight();
				return *this;
			}
			//全ての値を初期値に戻す
			DTL_CPP14_CONSTEXPR
				FileBMP& clear() noexcept {
				this->clearRange();
				return *this;
			}


			///// 代入 /////

			DTL_CPP14_CONSTEXPR
				FileBMP& setPointX(const Index_Size end_x_) noexcept {
				this->start_x = end_x_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setPointY(const Index_Size end_y_) noexcept {
				this->start_y = end_y_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setWidth(const Index_Size width_) noexcept {
				this->width = width_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setHeight(const Index_Size height_) noexcept {
				this->height = height_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setPoint(const Index_Size point_) noexcept {
				this->start_x = point_;
				this->start_y = point_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setPoint(const Index_Size end_x_, const Index_Size end_y_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size length_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = length_;
				this->height = length_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setRange(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept {
				this->start_x = end_x_;
				this->start_y = end_y_;
				this->width = width_;
				this->height = height_;
				return *this;
			}
			DTL_CPP14_CONSTEXPR
				FileBMP& setRange(const dtl::base::MatrixRange & matrix_range_) noexcept {
				this->start_x = matrix_range_.x;
				this->start_y = matrix_range_.y;
				this->width = matrix_range_.w;
				this->height = matrix_range_.h;
				return *this;
			}


			///// コンストラクタ /////

			constexpr FileBMP() noexcept = default;
			constexpr explicit FileBMP(const std::string & write_value_) noexcept
				:str(write_value_) {}
			constexpr explicit FileBMP(const std::string & write_value_, const std::size_t color_num_) noexcept
				:str(write_value_), color_num(color_num_) {}

			constexpr explicit FileBMP(const dtl::base::MatrixRange & matrix_range_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h) {}
			constexpr explicit FileBMP(const dtl::base::MatrixRange & matrix_range_, const std::string & write_value_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_) {}
			constexpr explicit FileBMP(const dtl::base::MatrixRange & matrix_range_, const std::string & write_value_, const std::size_t color_num_) noexcept
				:start_x(matrix_range_.x), start_y(matrix_range_.y),
				width(matrix_range_.w), height(matrix_range_.h),
				str(write_value_), color_num(color_num_) {}

			constexpr explicit FileBMP(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_) {}
			constexpr explicit FileBMP(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const std::string & write_value_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_) {}
			constexpr explicit FileBMP(const Index_Size end_x_, const Index_Size end_y_, const Index_Size width_, const Index_Size height_, const std::string & write_value_, const std::size_t color_num_) noexcept
				:start_x(end_x_), start_y(end_y_),
				width(width_), height(height_),
				str(write_value_), color_num(color_num_) {}
		};
	}
}

#endif //Included Dungeon Template Library