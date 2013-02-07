#include "CPlayerData.h"

CPlayerData::CPlayerData(std::string name)
{
    m_name = name;
    m_timesPlayed = 0;
    m_highestScore = 0;
    m_averageScore = 0;
    m_ranking = 0;
    m_peer = NULL;
}

CPlayerData::~CPlayerData()
{
    //dtor
}

std::string CPlayerData::getName()
{
    m_dataMutex.lock();
    std::string name = m_name;
    m_dataMutex.unlock();
    return name;
}
unsigned int CPlayerData::getRanking()
{
    m_dataMutex.lock();
    unsigned int ranking = m_ranking;
    m_dataMutex.unlock();
    return ranking;
}
unsigned int CPlayerData::getAverageScore()
{
    m_dataMutex.lock();
    unsigned int average = m_averageScore;
    m_dataMutex.unlock();
    return average;
}
unsigned int CPlayerData::getHighestScore()
{
    m_dataMutex.lock();
    unsigned int highestScore = m_highestScore;
    m_dataMutex.unlock();
    return highestScore;
}
unsigned int CPlayerData::getTimesPlayed()
{
    m_dataMutex.lock();
    unsigned int timesPlayed = m_timesPlayed;
    m_dataMutex.unlock();
    return timesPlayed;
}
ENetPeer* CPlayerData::getPeer()
{
    m_dataMutex.lock();
    ENetPeer* peer = m_peer;
    m_dataMutex.unlock();
    return peer;
}

void CPlayerData::setName(std::string name)
{
    m_dataMutex.lock();
    m_name = name;
    m_dataMutex.unlock();
}
void CPlayerData::setRanking(unsigned int ranking)
{
    m_dataMutex.lock();
    m_ranking = ranking;
    m_dataMutex.unlock();
}
void CPlayerData::setTimesPlayed(unsigned int times)
{
    m_dataMutex.lock();
    m_timesPlayed = times;
    m_dataMutex.unlock();
}
void CPlayerData::setAverageScore(unsigned int averageScore)
{
    m_dataMutex.lock();
    m_averageScore = averageScore;
    m_dataMutex.unlock();
}
void CPlayerData::setHighestScore(unsigned int highestScore)
{
    m_dataMutex.lock();
    m_highestScore = highestScore;
    m_dataMutex.unlock();
}
void CPlayerData::setPeer(ENetPeer *peer)
{
    m_dataMutex.lock();
    m_peer = peer;
    m_dataMutex.unlock();
}
sf::Packet  operator <<(sf::Packet packet, CPlayerData &P)
{
    return packet << P.getName() << P.getRanking() << P.getTimesPlayed() << P.getAverageScore() << P.getHighestScore();
}

sf::Packet  operator >>(sf::Packet packet, CPlayerData &P)
{
    std::string name;
    unsigned int timesPlayed;
    unsigned int ranking;
    unsigned int highestScore;
    unsigned int averageScore;
    return packet >> name >> ranking >> timesPlayed >> averageScore >> highestScore;
    P.setName(name);
    P.setRanking(ranking);
    P.setTimesPlayed(timesPlayed);
    P.setAverageScore(averageScore);
    P.setHighestScore(highestScore);
}
sf::Packet  operator <<(sf::Packet packet, CPlayerData *P)
{
    return packet << P->getName() << P->getRanking() << P->getTimesPlayed() << P->getAverageScore() << P->getHighestScore();
}

sf::Packet  operator >>(sf::Packet packet, CPlayerData *P)
{
    std::string name;
    unsigned int timesPlayed;
    unsigned int ranking;
    unsigned int highestScore;
    unsigned int averageScore;
    return packet >> name >> ranking >> timesPlayed >> averageScore >> highestScore;
    P->setName(name);
    P->setRanking(ranking);
    P->setTimesPlayed(timesPlayed);
    P->setAverageScore(averageScore);
    P->setHighestScore(highestScore);
}
