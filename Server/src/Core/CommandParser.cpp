/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CommandParser
*/

#include <map>
#include "CommandParser.hpp"
#include "RegisterCommand.hpp"
#include "LoginCommand.hpp"

using namespace bbl::srv;

typedef void(*strategyCallback)(std::vector<User *>, User *, IStorage *, const std::vector<std::string> &);

static const std::map<std::string, std::pair<strategyCallback, std::size_t>> _functions = {
    {"REGISTER", {RegisterCommand::run, 2}},
    {"LOGIN", {LoginCommand::run, 2}}
};

std::vector<std::string> CommandParser::split(std::string str, const std::string &delimiter)
{
    std::size_t pos = 0;
    std::string token;
    std::vector<std::string> list;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (token != "")
            list.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    if (str != "")
        list.push_back(str);
    return list;
}

void CommandParser::parse(std::vector<User *> _clients, User *current, IStorage *db, const std::string &text)
{
    std::string copy = text;
    auto idx = copy.find_last_of('\n');
    if (text == "\n") {
        current->getNetworkPart()->send("KO Invalid command\n");
        return;
    }
    if (idx != std::string::npos)
        copy.pop_back();
    auto list = split(copy, " ");
    for (auto &i : _functions) {
        if (i.first == list[0]) {
            if (list.size() >= i.second.second + 1)
                i.second.first(_clients, current, db, list);
            else
                current->getNetworkPart()->send("KO No enough arguments\n");
            return;
        }
    }
    current->getNetworkPart()->send("KO Invalid command\n");
}
