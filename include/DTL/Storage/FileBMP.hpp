﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BMP_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_STORAGE_FILE_BMP_HPP

/*#######################################################################################
	日本語リファレンス (Reference-JP)
	https://github.com/Kasugaccho/DungeonTemplateLibrary/wiki/dtl::storage::FileBMP-(ストレージクラス)/
#######################################################################################*/

#include <DTL/Storage/FileBaseBin.hpp>
#include <DTL/Type/UniquePtr.hpp>

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <DTL/ThirdParty/STB/stb_image_write.h>
#endif

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace storage { //"dtl::storage"名前空間に属する

/*#######################################################################################
	[概要] FileBMPとは "BMP形式の画像ファイルを出力する" 機能を持つクラスである。
#######################################################################################*/
		template<typename Matrix_Int_, typename UniquePtr_ = DTL_TYPE_UNIQUE_PTR<unsigned char[]>>
		class FileBMP : public ::dtl::storage::FileBaseBin<FileBMP<Matrix_Int_, UniquePtr_>, Matrix_Int_, UniquePtr_> {


			///// エイリアス (Alias) /////

			using FileBase_t = ::dtl::storage::FileBaseBin<FileBMP, Matrix_Int_, UniquePtr_>;

			friend FileBase_t;


			///// 基本処理 /////

			int writeFile(char const* filename, int width, int height, int color_num, const void* data) const {
				return ::stbi_write_bmp(filename, width, height, color_num, data);
			}

		public:


			///// コンストラクタ (Constructor) /////

			using FileBase_t::FileBase_t;
		};
	}
}

#endif //Included Dungeon Template Library
