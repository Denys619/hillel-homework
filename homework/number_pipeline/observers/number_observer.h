#pragma once

struct INumberObserver {
    virtual void on_number(int number) = 0;
    virtual void on_finished() = 0;
    virtual ~INumberObserver() = default;
};

struct PrintObserver: INumberObserver {
    void on_number(int number) override;
    void on_finished() override;
};

struct CountObserver: INumberObserver {
private:
    int count = 0;
public:
    void on_number(int nuber) override;
    void on_finished() override;
};
