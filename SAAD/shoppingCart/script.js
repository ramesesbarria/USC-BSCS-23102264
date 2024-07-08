document.addEventListener('DOMContentLoaded', function () {
    const cartItemsContainer = document.getElementById('cart-items');
    const totalPriceElement = document.getElementById('total-price');

    // Fetch items from the database and display them
    fetch('get_cart_items.php')
        .then(response => response.json())
        .then(data => {
            data.forEach(item => {
                const itemElement = createCartItemElement(item);
                cartItemsContainer.appendChild(itemElement);
            });
            updateTotalPrice();
        });

    function createCartItemElement(item) {
        const itemElement = document.createElement('div');
        itemElement.classList.add('flex', 'justify-between', 'items-center', 'p-4', 'border', 'border-gray-200', 'rounded');

        itemElement.innerHTML = `
            <div>
                <h2 class="text-lg font-semibold">${item.cartItemDescription}</h2>
                <p>Price: ₱ <span class="item-price">${item.cartPriceEach}</span></p>
            </div>
            <div class="flex items-center space-x-2">
                <button class="decrease-quantity bg-gray-300 px-2 py-1 rounded">-</button>
                <span class="item-quantity">${item.cartQuantity}</span>
                <button class="increase-quantity bg-gray-300 px-2 py-1 rounded">+</button>
            </div>
        `;

        itemElement.querySelector('.decrease-quantity').addEventListener('click', function () {
            updateQuantity(item.cartID, -1, itemElement);
        });

        itemElement.querySelector('.increase-quantity').addEventListener('click', function () {
            updateQuantity(item.cartID, 1, itemElement);
        });

        return itemElement;
    }

    function updateQuantity(cartID, change, itemElement) {
        const quantityElement = itemElement.querySelector('.item-quantity');
        let newQuantity = parseInt(quantityElement.textContent) + change;

        if (newQuantity <= 0) {
            // Remove item from cart
            fetch('update_cart_item.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ cartID, newQuantity })
            }).then(() => {
                itemElement.remove();
                updateTotalPrice();
            });
        } else {
            // Update item quantity
            fetch('update_cart_item.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ cartID, newQuantity })
            }).then(() => {
                quantityElement.textContent = newQuantity;
                updateTotalPrice();
            });
        }
    }

    function updateTotalPrice() {
        let total = 0;
        document.querySelectorAll('#cart-items .item-price').forEach((priceElement, index) => {
            const quantity = parseInt(document.querySelectorAll('#cart-items .item-quantity')[index].textContent);
            const price = parseFloat(priceElement.textContent);
            total += quantity * price;
        });
        totalPriceElement.textContent = total.toFixed(2);
    }

    document.getElementById('checkout-button').addEventListener('click', function () {
        window.location.href = 'checkout.html';
    });
});
