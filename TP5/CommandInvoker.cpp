///////////////////////////////////////////////////////////
//  CommandInvoker.cpp
//  Implementation of the Class CommandInvoker
//  Created on:      08-nov.-2018 21:05:19
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "CommandInvoker.h"

CommandInvoker* CommandInvoker::m_instance = nullptr;

CommandInvoker * CommandInvoker::getInstance(void){

	if (m_instance == nullptr) {
		m_instance = new CommandInvoker();
	}
	return m_instance;
}

void CommandInvoker::execute(const CmdPtr & cmd){

	cmd->execute();
	m_cmdDone.push_back(cmd);
	m_cmdUndone.clear();
}

void CommandInvoker::undo(){

	if (!m_cmdDone.empty()) {
		m_cmdDone.back()->cancel();
		m_cmdUndone.push_back(m_cmdDone.back());
		m_cmdDone.pop_back();
	}
}

void CommandInvoker::redo(){

	if (!m_cmdUndone.empty()) {
		m_cmdUndone.back()->execute();
		m_cmdDone.push_back(m_cmdUndone.back());
		m_cmdUndone.pop_back();
	}

}

size_t CommandInvoker::getDoneCount(void) const{

	return m_cmdDone.size();
}

size_t CommandInvoker::getUndoneCount(void) const{

	return m_cmdUndone.size();
}
