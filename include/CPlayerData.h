#ifndef CPLAYERDATA_H
#define CPLAYERDATA_H

#include <string>
#include <mutex>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <enet/enet.h>

class CPlayerData
{
    public:
        CPlayerData(std::string name);
        virtual ~CPlayerData();

        std::string getName();
        unsigned int getTimesPlayed();
        unsigned int getRanking();
        unsigned int getHighestScore();
        unsigned int getAverageScore();
        ENetPeer* getPeer();

        void setName(std::string name);
        void setTimesPlayed(unsigned int times);
        void setRanking(unsigned int ranking);
        void setHighestScore(unsigned int score);
        void setAverageScore(unsigned int averageScore);
        void setPeer(ENetPeer *peer);

        sf::FloatRect playerScreen;
    protected:
    private:
        std::string m_name;
        ENetPeer* m_peer;
        unsigned int m_timesPlayed;
        unsigned int m_ranking;
        unsigned int m_highestScore;
        unsigned int m_averageScore;
        /**
            @brief This is only needed for the server & only on runtime, so it won't be passed into the sf::Packet  when transfered.
        **/
        std::mutex m_dataMutex;
};

sf::Packet  operator<<(sf::Packet packet, CPlayerData &P);
sf::Packet  operator>>(sf::Packet packet, CPlayerData &P);

sf::Packet  operator<<(sf::Packet packet, CPlayerData *P);
sf::Packet  operator>>(sf::Packet packet, CPlayerData *P);

#endif // CPLAYERDATA_H
