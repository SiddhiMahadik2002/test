
const students = [{
    name: "Siddhi Mahadik",
    scores: { math: 95, english: 92, science: 88 }
},
{
    name: "Rahul Nikam",
    scores: { math: 75, english: 79, science: 82 }
},
{
    name: "Laisha W",
    scores: { math: 95, english: 85, science: 92 }
}
]

const averageScoresArray = students.map(student => {
    let sum = 0;
    let count = 0;


    for (let subject in student.scores) {
        sum += student.scores[subject];
        count++;
    }

    const averageScore = sum / count;

    return {
        name: student.name,
        averageScore: averageScore
    };
});

console.log(averageScoresArray);