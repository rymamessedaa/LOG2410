/****************************************************************************
**
** Classe TeamMember
** Author: p482457
** Date: 25-oct-2019
**
****************************************************************************/

#include "TeamMember.h"

// Define class static members
TeamComponentContainer TeamMember::m_emptyContainer;

TeamMember::TeamMember(std::string name, const QImage & photo)
{
	// intitialisation de m_name
	m_name = name;

	// intitialisation de m_image
	m_image = photo;

}

TeamMember::TeamMember(const TeamMember & mdd)
{
	//copie de m_name
	m_name = mdd.getName();

	//copie de m_image
	m_image = mdd.getImage();


}

TeamMember * TeamMember::clone(void) const
{
	// renvoi d'une nouvelle instance construite par copie avec l'objet actuelle
	return new TeamMember(*this);
}

const QImage & TeamMember::getImage(void) const
{
	// Renvoi de l'attribut m_image
	return m_image;
}

QImage & TeamMember::getImage(void)
{
	// Renvoi de l'attribut m_image
	return m_image;
}

std::string TeamMember::getName(void) const
{
	// Renvoi de l'attribut m_name
	return m_name;
}

void TeamMember::setName(std::string name)
{
	// modification de l'attribut m_name
	m_name = name;
}

AbsTeamComponent& TeamMember::addTeamComponent(const AbsTeamComponent&)
{
    // Truc pour que le code compile. Rien à changer
	return *(*(m_emptyContainer.begin()));
}

TeamComponentIterator TeamMember::begin()
{
	// Renvoi de TeamComponentIterator de begin()
	return this->begin();
}

TeamComponentIterator_const TeamMember::cbegin() const
{
	// Renvoi de TeamComponentIterator_const de cbegin()
	return this->cbegin();
}

TeamComponentIterator_const TeamMember::cend() const
{
	// Renvoi de TeamComponentIterator_const  de cend()
	return this->cend();
}

TeamComponentIterator TeamMember::end()
{
	// Renvoi de TeamComponentIterator  de end()
	return this->end();
}

void TeamMember::deleteTeamComponent(TeamComponentIterator_const)
{
	// Rien a faire, un membre ne peut pas avoir d'enfants
}

