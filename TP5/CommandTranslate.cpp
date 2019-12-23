/****************************************************************************
**
** Classe CommandTranslate
** Author: p482457
** Date: 17-nov-2019
**
****************************************************************************/

#include "CommandTranslate.h"
#include "MemberTextFindReplace.h"
#include "AbsTeamComponent.h"

std::pair<std::string, std::string> CommandTranslate::translations[] = {
{"Premier", "Prime"},
{"Ministre", "Minister"},
{"Chef de l'", "Chief of "},
{"Membre", "Member"},
{"du Parlement", "of Parliement"}
};

size_t CommandTranslate::translationsCount = sizeof(CommandTranslate::translations) / sizeof(std::pair<std::string, std::string>);


CommandTranslate::CommandTranslate(AbsTeamComponent & component, TargetLanguage language)
	: m_target(component), m_language(language)
{
}

void CommandTranslate::cancel()
{
	// Construire un visiteur de traduction et l'appliquer a la composante dans le sens inverse
	MemberTextFindReplace findReplace;
	for (std::pair<std::string, std::string> roles : translations) {
		switch (m_language) {
		case TargetLanguage::English_t:
			findReplace.setStrings(new std::string(roles.second), new std::string(roles.first));
			break;
		case TargetLanguage::French_t:
			findReplace.setStrings(new std::string(roles.first), new std::string(roles.second));
			break;
		}
		m_target.accept(findReplace);
	}
}

void CommandTranslate::execute()
{
	// Construire un visiteur de traduction et l'appliquer a la composante
	MemberTextFindReplace findReplace;
	for (std::pair<std::string, std::string> roles : translations) {
		switch (m_language) {
		case TargetLanguage::English_t:
			findReplace.setStrings(new std::string(roles.first), new std::string(roles.second));
			break;
		case TargetLanguage::French_t:
			findReplace.setStrings(new std::string(roles.second), new std::string(roles.first));
			break;
		}
		m_target.accept(findReplace);
	}
}
