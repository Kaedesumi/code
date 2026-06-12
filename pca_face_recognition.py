import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import fetch_olivetti_faces
from sklearn.model_selection import train_test_split
from sklearn.decomposition import PCA
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, classification_report


def main():
    # 1. 读取数据集（首次运行会自动下载）
    faces = fetch_olivetti_faces(shuffle=True, random_state=42)

    X = faces.data          # shape: (400, 4096)，每张图 64x64 展平
    y = faces.target        # 40个人，每人10张
    images = faces.images   # shape: (400, 64, 64)

    print("数据集加载完成")
    print("X.shape =", X.shape)
    print("y.shape =", y.shape)
    print("类别数 =", len(np.unique(y)))

    # 2. 划分训练集与测试集（分层抽样）
    X_train, X_test, y_train, y_test = train_test_split(
        X, y,
        test_size=0.2,
        stratify=y,
        random_state=42
    )

    print("\n训练集大小:", X_train.shape[0])
    print("测试集大小:", X_test.shape[0])

    # 3. 比较不同主成分个数下的识别效果
    k_list = [10, 20, 30, 50, 80, 100, 150]
    acc_list = []

    print("\n不同主成分维数下的识别准确率：")
    for k in k_list:
        pca = PCA(n_components=k, whiten=True, svd_solver='randomized', random_state=42)
        X_train_pca = pca.fit_transform(X_train)
        X_test_pca = pca.transform(X_test)

        clf = KNeighborsClassifier(n_neighbors=1, metric='euclidean')
        clf.fit(X_train_pca, y_train)

        y_pred = clf.predict(X_test_pca)
        acc = accuracy_score(y_test, y_pred)
        acc_list.append(acc)

        print(f"k = {k:3d}, 准确率 = {acc:.4f}")

    # 4. 选一个较合适的k做最终实验
    best_index = int(np.argmax(acc_list))
    best_k = k_list[best_index]
    best_acc = acc_list[best_index]

    print(f"\n最佳主成分数: k = {best_k}, 准确率 = {best_acc:.4f}")

    pca = PCA(n_components=best_k, whiten=True, svd_solver='randomized', random_state=42)
    X_train_pca = pca.fit_transform(X_train)
    X_test_pca = pca.transform(X_test)

    clf = KNeighborsClassifier(n_neighbors=1, metric='euclidean')
    clf.fit(X_train_pca, y_train)

    y_pred = clf.predict(X_test_pca)

    print("\n分类报告：")
    print(classification_report(y_test, y_pred, zero_division=0))

    # 5. 画图：准确率随k变化
    plt.figure(figsize=(8, 5))
    plt.plot(k_list, acc_list, marker='o')
    plt.xlabel("主成分个数 k")
    plt.ylabel("识别准确率")
    plt.title("PCA主成分个数与人脸识别准确率")
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    # 6. 显示均值脸和前几张特征脸（Eigenfaces）
    mean_face = pca.mean_.reshape(64, 64)
    eigenfaces = pca.components_.reshape((best_k, 64, 64))

    plt.figure(figsize=(10, 4))
    plt.subplot(2, 5, 1)
    plt.imshow(mean_face, cmap='gray')
    plt.title("均值脸")
    plt.axis("off")

    for i in range(1, 10):
        plt.subplot(2, 5, i + 1)
        plt.imshow(eigenfaces[i - 1], cmap='gray')
        plt.title(f"特征脸{i}")
        plt.axis("off")

    plt.tight_layout()
    plt.show()

    # 7. 显示部分测试结果
    n_show = 10
    plt.figure(figsize=(12, 5))
    for i in range(n_show):
        plt.subplot(2, 5, i + 1)
        plt.imshow(X_test[i].reshape(64, 64), cmap='gray')
        plt.title(f"真:{y_test[i]} 预测:{y_pred[i]}")
        plt.axis("off")
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()