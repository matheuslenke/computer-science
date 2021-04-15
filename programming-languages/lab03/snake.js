const board = document.getElementById("snakeboard");
const boardContext = board.getContext("2d");


function clearBoard() {
    boardContext.fillStyle = "white";
    boardContext.strokestyle = "black";
    boardContext.fillRect(0, 0, board.width , board.height );
    boardContext.strokeRect(0, 0, board.width , board.height );
}

clearBoard();

let snake = [
    {x: 200, y: 200},
    {x: 190, y: 200},
    {x: 180, y: 200},
    {x: 170, y: 200},
    {x: 160, y: 200},
]

let velocity = {
    dy: 0,
    dx: 10,
}
let score = 0;

let food = {x: 10, y: 10};

let changingDirection = false;


function startGame() {
    clearBoard();

    snake = [
        {x: 200, y: 200},
        {x: 190, y: 200},
        {x: 180, y: 200},
        {x: 170, y: 200},
        {x: 160, y: 200},
    ]

    velocity = {
        dy: 0,
        dx: 10,
    }
    score = 0;

    food = {x: 10, y: 10};

    document.getElementById("score").innerHTML = 0;
}

function drawSnakePart(snakePart) {
    boardContext.fillStyle = "lightblue";
    boardContext.strokestyle = "darkblue";
    boardContext.fillRect(snakePart.x, snakePart.y, 10, 10);
    boardContext.strokeRect(snakePart.x, snakePart.y, 10, 10);
}

function drawSnake() {
    snake.forEach(drawSnakePart);
}


function drawFood(foodCoord) {
    boardContext.fillStyle = "green";
    boardContext.strokestyle = "darkGreen";
    boardContext.fillRect(foodCoord.x, foodCoord.y, 10, 10);
    boardContext.strokeRect(foodCoord.x, foodCoord.y, 10, 10);
}


function sameCoords(one, two) {
    return (one.x === two.x) && (one.y === two.y);
}

function randomFoodCoord(min, max) {
    return Math.round((Math.random() * (max-min) + min) / 10) * 10;
}

function generateFood() {
    food.x = randomFoodCoord(0, board.width - 10);
    food.y = randomFoodCoord(0, board.height - 10);

    snake.forEach(
        part => {
            if(sameCoords(part, food)) generateFood();
        }
    )
}

function moveSnake() {
    const head = {
        x: snake[0].x + velocity.dx,
        y: snake[0].y + velocity.dy
    };

    snake.unshift(head);
    if(sameCoords(head,food)) {

        score += 10;

        document.getElementById("score").innerHTML = score;

        generateFood();
    } else {
        snake.pop();
    }
}

function changeDirection(event) {
    const LEFT_KEY = 37;
    const RIGHT_KEY = 39;
    const UP_KEY = 38;
    const DOWN_KEY = 40;

    if(changingDirection) return;
    changingDirection = true;

    console.log("Changed")

    const keyPressed = event.keyCode;
    const goingUp = velocity.dy === -10;
    const goingDown = velocity.dy === 10;
    const goingRight = velocity.dx === 10;
    const goingLeft = velocity.dx === -10;

    if(keyPressed === LEFT_KEY && !goingRight) {
        velocity.dx = -10;
        velocity.dy = 0;
    } else if(keyPressed === UP_KEY && !goingDown) {
        velocity.dx = 0;
        velocity.dy = -10;
    } else if(keyPressed === RIGHT_KEY && !goingLeft) {
        velocity.dx = 10;
        velocity.dy = 0;
    } else if(keyPressed === DOWN_KEY && !goingUp) {
        velocity.dx = 0;
        velocity.dy = 10;
    }
}

function gameOver() {
    let head = snake[0];

    for(let i = 4; i < snake.length; i++) {
        if(sameCoords(head, snake[i])) return true;
    }

    const hitLeftWall = head.x < 0;
    const hitRightWall = head.x > board.width - 10;
    const hitTopWall = head.y < 0;
    const hitBottomWall = head.y > board.height - 10;
    return hitLeftWall || hitRightWall || hitTopWall || hitBottomWall;
}

let askedToRestart = false;


function mainLoop() {
    if(gameOver() === true) {
        document.getElementById("score").innerHTML = "Game Over!"
        return;
    }
    if (askedToRestart === true) return;

    changingDirection = false;
    setTimeout(function onTick() {
        clearBoard();
        drawFood(food);
        moveSnake();
        drawSnake();
        mainLoop();
    }, 100);
}

function run() {
    document.addEventListener("keydown", changeDirection);
    generateFood();
    mainLoop();
}

run();

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function playAgain() {
    askedToRestart = true;
    await sleep(400);
    startGame();
    generateFood();
    askedToRestart = false;
    mainLoop();
}