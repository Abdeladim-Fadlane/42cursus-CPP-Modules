
import requests

from bs4 import BeautifulSoup

import csv


# date = input("please enter a Date MM/DD/YYYY:")
# page = requests.get(f"https://www.yallakora.com/Match-Center/?date={date}")
page = requests.get("https://www.yallakora.com/Match-Center/?date=10/05/2023")

def main(page):

    src = page.content
    soup = BeautifulSoup(src,"lxml")
    matchDetails = []
    champ_list = soup.find_all("div",{'class' : 'matchCard'})
    
    def getInfo(champ_list):
        champTitle = champ_list.contents[1].find('h2').text.strip()
        allMatch = champ_list.contents[3].find_all('li')
        numberMatch = len(allMatch)

        for i in range(numberMatch):
            team1 = allMatch[i].find('div',{'class' : 'teamA'}).text.strip()
            team2 = allMatch[i].find('div',{'class' : 'teamB'}).text.strip()

            matchResult = allMatch[i].find('div',{'class' : 'MResult'}).find_all('span',{'class': 'score'})
            score = f"{matchResult[0].text.strip()} - {matchResult[1].text.strip()}"

            matchTime = allMatch[i].find('div',{'class' : 'MResult'}).find('span',{'class':'time'}).text.strip()

            matchDetails.append({"Tournament" : champTitle,"Team 1" : team1,"Team 2" : team2,
                                "Time Match" : matchTime,"Score":score})
        # print(numberMatch)
    for i in range (len(champ_list)):
        getInfo(champ_list[i])
    
    keys = matchDetails[0].keys()

    with open('scraping.csv','w') as outputFile:
        dicWriter = csv.DictWriter(outputFile,keys)
        dicWriter.writeheader()
        dicWriter.writerows(matchDetails)
        print("file created")
main(page)