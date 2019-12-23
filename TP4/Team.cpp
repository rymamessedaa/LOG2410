#include "Team.h"

Team::Team(std::string name)
{
	// intitialisation de m_name
	m_name = name;
}

Team::Team(const Team & mdd)
{
	//copie de m_name
	m_name = mdd.getName();

	//copie de m_image
	m_image = mdd.getImage();

	//copie de m_members
	m_members = mdd.m_members;
}

Team * Team::clone(void) const
{
	// renvoi d'une nouvelle instance construite par copie avec l'objet actuelle
	return new  Team(*this);
}

const QImage & Team::getImage(void) const
{
	// Renvoi de l'attribut m_image
	return m_image;
}

QImage & Team::getImage(void)
{
	// Renvoi de l'attribut m_image
	return m_image;
}

std::string Team::getName(void) const
{
	// Renvoi de l'attribut m_name
	return m_name;
}

void Team::setName(std::string name)
{
	// modification de l'attribut m_name
	m_name = name;
}

AbsTeamComponent& Team::addTeamComponent(const AbsTeamComponent & member)
{
	//  Ajouter un nouvel element, TeamComponentPtr, dans la liste m_members
	m_members.push_back( TeamComponentPtr( member.clone() ) );

	// retrourner une reference a l'objet insere dans la liste
	return *( m_members.back() );
}

TeamComponentIterator Team::begin()
{
	// retourner un iterateur vers le premier objet dans la liste m_mebers
	return m_members.begin();
}

TeamComponentIterator_const Team::cbegin() const
{
	// retourner un iterateur vers le premier objet dans la liste m_mebers
	return m_members.cbegin();
}

TeamComponentIterator_const Team::cend() const
{
	// retourner un iterateur vers la fin de la liste m_mebers
	return m_members.cend();
}

TeamComponentIterator Team::end()
{
	// retourner un iterateur vers la fin de la liste m_mebers
	return m_members.end();
}

void Team::deleteTeamComponent(TeamComponentIterator_const child)
{
	//eliminer de la liste l'element indique par l'iterateur child
	m_members.erase(child);
}

void Team::deleteAllComponents(void)
{
	//vider la liste et les attributs membres
	m_members.clear();
	m_name = "";

}
