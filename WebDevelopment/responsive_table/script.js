document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('student-form');
    const tableBody = document.querySelector('#student-table tbody');

    form.addEventListener('submit', function(event) {
        event.preventDefault();
        const idNumber = form.elements['id-number'].value;
        const name = form.elements['name'].value;
        const age = form.elements['age'].value;
        const courseYear = form.elements['course-year'].value;

        const newRow = document.createElement('tr');
        newRow.innerHTML = `
            <td><input type="text" class="editable" value="${idNumber}" readonly></td>
            <td><input type="text" class="editable" value="${name}"></td>
            <td><input type="number" class="editable" value="${age}"></td>
            <td><input type="text" class="editable" value="${courseYear}"></td>
            <td><button class="delete-btn">Delete</button></td>
        `;
        tableBody.appendChild(newRow);

        form.reset();
    });


    tableBody.addEventListener('click', function(event) {
        if (event.target.classList.contains('delete-btn')) {
            const row = event.target.closest('tr');
            row.remove();
        }
    });

    tableBody.addEventListener('dblclick', function(event) {
        if (event.target.classList.contains('editable')) {
            event.target.readOnly = false;
            event.target.focus();
        }
    });


    tableBody.addEventListener('blur', function(event) {
        if (event.target.classList.contains('editable')) {
            event.target.readOnly = true;
        }
    }, true); 
});
