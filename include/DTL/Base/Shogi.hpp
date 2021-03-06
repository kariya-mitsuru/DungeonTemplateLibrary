﻿/*#######################################################################################
	Copyright (c) 2017-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/DungeonTemplateLibrary
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_SHOGI_HPP
#define INCLUDED_DUNGEON_TEMPLATE_LIBRARY_DTL_BASE_SHOGI_HPP

/*#######################################################################################
	[概要] "dtl名前空間"とは"DungeonTemplateLibrary"の全ての機能が含まれる名前空間である。
	[Summary] The "dtl" is a namespace that contains all the functions of "DungeonTemplateLibrary".
#######################################################################################*/
namespace dtl {
	inline namespace base { //"dtl::base"名前空間に属する

		template<typename Matrix_Int_>
		struct ShogiList {
			Matrix_Int_ fuhyo_1{};
			Matrix_Int_ fuhyo_2{};
			Matrix_Int_ tokin_1{};
			Matrix_Int_ tokin_2{};
			Matrix_Int_ kyosha_1{};
			Matrix_Int_ kyosha_2{};
			Matrix_Int_ narikyo_1{};
			Matrix_Int_ narikyo_2{};
			Matrix_Int_ keima_1{};
			Matrix_Int_ keima_2{};
			Matrix_Int_ narikei_1{};
			Matrix_Int_ narikei_2{};
			Matrix_Int_ ginsho_1{};
			Matrix_Int_ ginsho_2{};
			Matrix_Int_ narigin_1{};
			Matrix_Int_ narigin_2{};
			Matrix_Int_ hisha_1{};
			Matrix_Int_ hisha_2{};
			Matrix_Int_ ryuo_1{};
			Matrix_Int_ ryuo_2{};
			Matrix_Int_ kakugyo_1{};
			Matrix_Int_ kakugyo_2{};
			Matrix_Int_ ryuma_1{};
			Matrix_Int_ ryuma_2{};
			Matrix_Int_ kinsho_1{};
			Matrix_Int_ kinsho_2{};
			Matrix_Int_ osho{};
			Matrix_Int_ gyokusho{};

			ShogiList() = default;

			constexpr ShogiList(
				const Matrix_Int_& fuhyo_1_,
				const Matrix_Int_& fuhyo_2_,
				const Matrix_Int_& tokin_1_,
				const Matrix_Int_& tokin_2_,
				const Matrix_Int_& kyosha_1_,
				const Matrix_Int_& kyosha_2_,
				const Matrix_Int_& narikyo_1_,
				const Matrix_Int_& narikyo_2_,
				const Matrix_Int_& keima_1_,
				const Matrix_Int_& keima_2_,
				const Matrix_Int_& narikei_1_,
				const Matrix_Int_& narikei_2_,
				const Matrix_Int_& ginsho_1_,
				const Matrix_Int_& ginsho_2_,
				const Matrix_Int_& narigin_1_,
				const Matrix_Int_& narigin_2_,
				const Matrix_Int_& hisha_1_,
				const Matrix_Int_& hisha_2_,
				const Matrix_Int_& ryuo_1_,
				const Matrix_Int_& ryuo_2_,
				const Matrix_Int_& kakugyo_1_,
				const Matrix_Int_& kakugyo_2_,
				const Matrix_Int_& ryuma_1_,
				const Matrix_Int_& ryuma_2_,
				const Matrix_Int_& kinsho_1_,
				const Matrix_Int_& kinsho_2_,
				const Matrix_Int_& osho_,
				const Matrix_Int_& gyokusho_) noexcept :
				fuhyo_1(fuhyo_1_),
				fuhyo_2(fuhyo_2_),
				tokin_1(tokin_1_),
				tokin_2(tokin_2_),
				kyosha_1(kyosha_1_),
				kyosha_2(kyosha_2_),
				narikyo_1(narikyo_1_),
				narikyo_2(narikyo_2_),
				keima_1(keima_1_),
				keima_2(keima_2_),
				narikei_1(narikei_1_),
				narikei_2(narikei_2_),
				ginsho_1(ginsho_1_),
				ginsho_2(ginsho_2_),
				narigin_1(narigin_1_),
				narigin_2(narigin_2_),
				hisha_1(hisha_1_),
				hisha_2(hisha_2_),
				ryuo_1(ryuo_1_),
				ryuo_2(ryuo_2_),
				kakugyo_1(kakugyo_1_),
				kakugyo_2(kakugyo_2_),
				ryuma_1(ryuma_1_),
				ryuma_2(ryuma_2_),
				kinsho_1(kinsho_1_),
				kinsho_2(kinsho_2_),
				osho(osho_),
				gyokusho(gyokusho_) {}

			constexpr ShogiList(
				const Matrix_Int_& fuhyo_,
				const Matrix_Int_& tokin_,
				const Matrix_Int_& kyosha_,
				const Matrix_Int_& narikyo_,
				const Matrix_Int_& keima_,
				const Matrix_Int_& narikei_,
				const Matrix_Int_& ginsho_,
				const Matrix_Int_& narigin_,
				const Matrix_Int_& hisha_,
				const Matrix_Int_& ryuo_,
				const Matrix_Int_& kakugyo_,
				const Matrix_Int_& ryuma_,
				const Matrix_Int_& kinsho_,
				const Matrix_Int_& osho_) noexcept :
				fuhyo_1(fuhyo_),
				fuhyo_2(fuhyo_),
				tokin_1(tokin_),
				tokin_2(tokin_),
				kyosha_1(kyosha_),
				kyosha_2(kyosha_),
				narikyo_1(narikyo_),
				narikyo_2(narikyo_),
				keima_1(keima_),
				keima_2(keima_),
				narikei_1(narikei_),
				narikei_2(narikei_),
				ginsho_1(ginsho_),
				ginsho_2(ginsho_),
				narigin_1(narigin_),
				narigin_2(narigin_),
				hisha_1(hisha_),
				hisha_2(hisha_),
				ryuo_1(ryuo_),
				ryuo_2(ryuo_),
				kakugyo_1(kakugyo_),
				kakugyo_2(kakugyo_),
				ryuma_1(ryuma_),
				ryuma_2(ryuma_),
				kinsho_1(kinsho_),
				kinsho_2(kinsho_),
				osho(osho_),
				gyokusho(osho_) {}
		};
	}
}

#endif //Included Dungeon Template Library