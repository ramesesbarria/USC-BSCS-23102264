function validateForm() {
    var username = document.getElementById("username").value;
    var firstName = document.getElementById("firstName").value;
    var lastName = document.getElementById("lastName").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;

    if (username === "" || firstName === "" || lastName === "" || email === "" || password === "") {
        alert("All fields must be filled out");
        return false;
    }

    if (username.length < 5 || username.length > 15) {
        alert("Username must be between 5 and 15 characters");
        return false;
    }

    if (password.length < 8) {
        alert("Password must be at least 8 characters");
        return false;
    }

    if (!validateEmail(email)) {
        showModal("Invalid email format");
        return false;
    }

    showModal("Registration successful");
    return false;
}

function validateEmail(email) {
    var re = /\S+@\S+\.\S+/;
    return re.test(email);
}

function showModal(message) {
    var modal = document.getElementById("modal");
    var modalMessage = document.getElementById("modalMessage");
    modal.style.display = "block";
    modalMessage.innerHTML = message;

    var closeBtn = document.getElementsByClassName("close")[0];
    closeBtn.onclick = function () {
        modal.style.display = "none";
    }

    window.onclick = function (event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }
}
