/*
// [1, 2, 3, 4, 5, 6, 7, 8]
// надо сделать чтобы в финал попали самые сильные - это 1 и 2, то есть поставить 2 во вторую часть

Правильно рассортировать участников турнира по силе за линейную сложность
До 10 n
без рекурсии и без двойного for
Одним проходом по циклу
Итог - отсортированный массив
На вход n

n - число раундов

если 16
1 - 16
9 - 8
5 - 12
13 - 4
3 - 14
11 - 6
7 - 10
15 - 2 
*/

let n = 32;

let participants = Array.from({length: n}, (v, k) => k + 1);
let bracket = getBracket(participants);

console.log(participants);
console.log(bracket);

function getBracket(participants) {
   let participantsCount = participants.length;
   let rounds = Math.ceil(Math.log(participantsCount) / Math.log(2)); // кол-во раундов через округление вверх и логарифм
   // если 16 уч то 4 / 1 = 4 раунда
   let bracketSize = Math.pow(2, rounds); // 2 в степени кол-ва раундов(2^4 = 16)
   let requiredByes = bracketSize - participantsCount; // обязательный выход - проверка на правильность, если 0 - то пока все верно

  console.log(`Number of participants: ${participantsCount}`);
  console.log(`Number of rounds: ${rounds}`);
  console.log(`Bracket size: ${bracketSize}`);
  console.log(`Required number of byes: ${requiredByes}`);

  if (participantsCount < 2) {
    return [];
  }

  let matches = [[1, 2]]; // нужное совпадение - двумерный массив

  for (let round = 1; round < rounds; round++) {
    let roundMatches = []; // нужное совпадение пока пустой двумерный массив, потом буду пушить в него необходимых участников
    let sum = Math.pow(2, round + 1) + 1; // 5, 9, 17 для n = 16, сумма 2 чисел в массиве всегда 17
    // console.log(sum);
    // console.log(`matches: ${matches}`);
    console.log(`matches.length: ${matches.length}`);
    // matches.length - 1, 2 и 4 - это тур, в котором будут участвовать команды. 
    // Соответсвенно в 4 туре абсолютно все участники
    // во 2 туре лучшие 8 участников
    // в первом туре топ 4 
    for (let i = 0; i < matches.length; i++) {
      let home = changeIntoBye(matches[i][0], participantsCount);
      console.log(`home1: ${home}`);
      let away = changeIntoBye(sum - matches[i][0], participantsCount);
      console.log(`away1: ${away}`);
      roundMatches.push([home, away]);
      home = changeIntoBye(sum - matches[i][1], participantsCount);
      console.log(`home2: ${home}`);
      away = changeIntoBye(matches[i][1], participantsCount);
      console.log(`away2: ${away}`);
      roundMatches.push([home, away]);
    }
    matches = roundMatches;
  }
  return matches

}
// заполнение-проверка
function changeIntoBye(seed, participantsCount) {
  return seed <= participantsCount ? seed : null;
  // функция заполнения если сид(одно число в массиве 2-х) <= 16 то заполняем, иначе null - такого участника быть не может
}
