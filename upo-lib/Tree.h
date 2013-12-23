/*
Copyright (c) 2013, Daniel Randall
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

* Neither the name of the Universal Programming Organization nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __Library__Tree__
#define __Library__Tree__

#include "List.h"

class TreeBranch // represents a Tree Branch
{
	private:
		List m_Branches;

	public:
		OBJECT* m_pObject;

		TreeBranch(OBJECT* pObject);
		
		~TreeBranch();
		
		// adds a branch to the tail of the branch list:
		TreeBranch* AddBranch(OBJECT* pObject);
		
		// removes the head branch and returns its object pointer:
		OBJECT* RemoveBranch();
		
		// get pointer to next branch:
		ListElement* getNextBranch(ListElement* pElement);

		// get count of child branches:
		uint32_t getBranchCount();
		
		// utility for accessing the branch object in a list element:
		static TreeBranch* asBranch(ListElement* pElement);
};

inline TreeBranch* TreeBranch::asBranch(ListElement* pElement)
{
	return (pElement) ? (TreeBranch*)pElement->m_pObject : NULL;
}

class Tree // represents a Tree
{
	private:
		TreeBranch* m_pTrunk;
		
	public:
		TreeBranch* getTrunk();
		
		Tree(OBJECT* pObject);
		
		~Tree();
};


#endif /* defined(__Library__Tree__) */