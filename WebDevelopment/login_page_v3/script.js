// Toggle between login and registration pages
document.querySelector('a[href="#"]').addEventListener('click', function (e) {
    e.preventDefault();
    document.getElementById('login-page').style.display = 'none';
    document.getElementById('registration-page').style.display = 'block';
});

// Toggle between dark and light mode
let darkMode = false;
document.getElementById('darkModeToggle').addEventListener('click', function () {
    darkMode = !darkMode;
    document.body.classList.toggle('dark-mode', darkMode);
});

// Example of changing content based on sidebar click
document.querySelectorAll('.list-group-item').forEach(function (item) {
    item.addEventListener('click', function () {
        document.getElementById('content').innerHTML = `You clicked on ${item.textContent}`;
    });
});

// Simulate login functionality
document.querySelector('#login-page form').addEventListener('submit', function (e) {
    e.preventDefault();
    const emailOrUsername = document.getElementById('emailOrUsername').value;
    alert(`Logged in as ${emailOrUsername}`);
    // You can redirect to the dashboard or perform other actions here
});

// Simulate registration functionality
document.querySelector('#registration-page form').addEventListener('submit', function (e) {
    e.preventDefault();
    const email = document.getElementById('email').value;
    const firstName = document.getElementById('firstName').value;
    const lastName = document.getElementById('lastName').value;
    alert(`Registered as ${firstName} ${lastName} (${email})`);
    // You can redirect to the login page or perform other actions here
});

// Example profile and logout button actions
document.getElementById('profileButton').addEventListener('click', function () {
    alert('View profile');
    // You can implement profile viewing functionality here
});

document.getElementById('logoutButton').addEventListener('click', function () {
    alert('Logged out');
    // You can implement logout functionality here
});
