/*
 * Copyright (c) 2020 The Whatcoin developer
 * Distributed under the MIT software license, see the accompanying
 * file COPYING or http://www.opensource.org/licenses/mit-license.php.
 * 
 * FounderPayment.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Tri Nguyen
 */

#ifndef SRC_FOUNDER_PAYMENT_H_
#define SRC_FOUNDER_PAYMENT_H_
#include <string>
#include "amount.h"
#include "primitives/transaction.h"
#include "script/standard.h"
#include <limits.h>
//using namespace std;

static const std::string DEFAULT_FOUNDER_ADDRESS = "kmqsVCyUELe4uV9A7UsFAckre8ceYHRUrT";
static const std::string BURN_FOUNDER_ADDRESS = "kburnXXXXXXXXXXXXXXXXXXXXXXXXswNF4"; 
static const int BURN_FOUNDER_ADDRESS_BLOCK_HEIGHT = 64975;
struct FounderRewardStructure {
	int blockHeight;
	int rewardPercentage;
};

class FounderPayment {
public:
	FounderPayment(std::vector <FounderRewardStructure> rewardStructures = {}, int startBlock = 0, const std::string &address = DEFAULT_FOUNDER_ADDRESS, const std::string &newAddress =  BURN_FOUNDER_ADDRESS, int newAddressStartBlock = BURN_FOUNDER_ADDRESS_BLOCK_HEIGHT ) {
		this->founderAddress = address;
		this->newFounderAddress = newAddress;
		this->newFounderAddressStartBlock = newAddressStartBlock;
		this->startBlock = startBlock;
		this->rewardStructures = rewardStructures;
	}
	~FounderPayment(){};
	CAmount getFounderPaymentAmount(int blockHeight, CAmount blockReward);
	void FillFounderPayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockReward, CTxOut& txoutFounderRet);
	bool IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockReward);
	int getStartBlock() {return this->startBlock;}
private:
	std::string founderAddress;
	std::string newFounderAddress;
	int newFounderAddressStartBlock;
	int startBlock;
	std::vector <FounderRewardStructure> rewardStructures;
};



#endif /* SRC_FOUNDER_PAYMENT_H_ */