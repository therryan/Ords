/* Copyright 2010 Teemu Vasama. Ords is distributed under the GPLv3.
 *
 * This file is part of Ords.
 *
 *   Ords is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 3
 *   as published by the Free Software Foundation.
 *
 *   Ords is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License 
 *	 (the LICENSE file) along with Ords.
 *	 If not, see <http://www.gnu.org/licenses/>.
 */

// 
// 		src/data/conjugation.h -- The Conjugation class
// 	
// The Conjugation class is used for words that conjugate heavily, such as irregular verbs

#ifndef CONJUGATION_H
#define CONJUGATION_H 

#include "../utils/utils.h"

class Conjugation
{
	private:

	public:
		Conjugation();
		
		string save();
		string repr();
};

#endif
